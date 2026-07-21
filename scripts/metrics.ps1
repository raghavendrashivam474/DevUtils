# ==============================================================
# scripts/metrics.ps1
#
# DevUtils — Sprint Metrics Calculator
#
# Counts source files, header files, lines of C++, and other
# repository metrics automatically.
#
# Usage:
#   .\scripts\metrics.ps1
#   .\scripts\metrics.ps1 -Utility Calculator
# ==============================================================

param (
    [string]$Utility = ""
)

$root = Split-Path -Parent $PSScriptRoot

# ──────────────────────────────────────────────
# Scope: single utility or entire repository
# ──────────────────────────────────────────────
if ($Utility -ne "") {
    $searchPath = Join-Path $root "apps\$Utility"
    if (-not (Test-Path $searchPath)) {
        Write-Host "[!] Utility '$Utility' not found at $searchPath" -ForegroundColor Red
        exit 1
    }
    $scope = "apps/$Utility"
} else {
    $searchPath = Join-Path $root "apps"
    $scope = "All utilities"
}

Write-Host ""
Write-Host "======================================" -ForegroundColor Cyan
Write-Host "  DevUtils — Sprint Metrics" -ForegroundColor Cyan
Write-Host "  Scope: $scope" -ForegroundColor Cyan
Write-Host "======================================" -ForegroundColor Cyan
Write-Host ""

# ──────────────────────────────────────────────
# Collect files
# ──────────────────────────────────────────────
$cppFiles    = Get-ChildItem -Recurse -Path $searchPath -Filter "*.cpp" -ErrorAction SilentlyContinue
$hppFiles    = Get-ChildItem -Recurse -Path $searchPath -Filter "*.hpp" -ErrorAction SilentlyContinue
$hFiles      = Get-ChildItem -Recurse -Path $searchPath -Filter "*.h"   -ErrorAction SilentlyContinue
$cmakeFiles  = Get-ChildItem -Recurse -Path $searchPath -Filter "CMakeLists.txt" -ErrorAction SilentlyContinue
$mdFiles     = Get-ChildItem -Recurse -Path $searchPath -Filter "*.md"  -ErrorAction SilentlyContinue

$allHeaders  = @($hppFiles) + @($hFiles)
$allSource   = $cppFiles

# ──────────────────────────────────────────────
# Count lines
# ──────────────────────────────────────────────
function Count-Lines($files) {
    $total = 0
    foreach ($f in $files) {
        if ($null -ne $f) {
            $total += (Get-Content $f.FullName -ErrorAction SilentlyContinue).Count
        }
    }
    return $total
}

$cppLines    = Count-Lines $cppFiles
$hppLines    = Count-Lines $allHeaders
$totalCppLines = $cppLines + $hppLines

# ──────────────────────────────────────────────
# Count executables in build
# ──────────────────────────────────────────────
$buildPath = Join-Path $root "build"
$exeFiles  = Get-ChildItem -Recurse -Path $buildPath -Filter "*.exe" -ErrorAction SilentlyContinue |
             Where-Object { $_.FullName -notlike "*CMakeFiles*" }

# ──────────────────────────────────────────────
# Repository-wide git stats
# ──────────────────────────────────────────────
$totalCommits = (git -C $root rev-list --count HEAD 2>$null)
$currentTag   = (git -C $root describe --tags --abbrev=0 2>$null)
$branch       = (git -C $root branch --show-current 2>$null)

# ──────────────────────────────────────────────
# Display results
# ──────────────────────────────────────────────
Write-Host "  -- Source Files --" -ForegroundColor Yellow
Write-Host "  .cpp files          : $($cppFiles.Count)"
Write-Host "  .hpp / .h files     : $($allHeaders.Count)"
Write-Host "  Total source files  : $($cppFiles.Count + $allHeaders.Count)"
Write-Host ""

Write-Host "  -- Lines of C++ --" -ForegroundColor Yellow
Write-Host "  Implementation lines: $cppLines"
Write-Host "  Header lines        : $hppLines"
Write-Host "  Total C++ lines     : $totalCppLines"
Write-Host ""

Write-Host "  -- Build & CMake --" -ForegroundColor Yellow
Write-Host "  CMakeLists.txt files: $($cmakeFiles.Count)"
Write-Host "  Executables built   : $($exeFiles.Count)"
if ($exeFiles.Count -gt 0) {
    foreach ($exe in $exeFiles) {
        Write-Host "    -> $($exe.Name)"
    }
}
Write-Host ""

Write-Host "  -- Documentation --" -ForegroundColor Yellow
Write-Host "  Markdown files      : $($mdFiles.Count)"
Write-Host ""

Write-Host "  -- Repository --" -ForegroundColor Yellow
Write-Host "  Current branch      : $branch"
Write-Host "  Current tag         : $currentTag"
Write-Host "  Total commits       : $totalCommits"
Write-Host ""

Write-Host "======================================" -ForegroundColor Cyan
Write-Host ""
