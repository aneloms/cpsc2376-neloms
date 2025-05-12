# Bug Fixes for practice03

## 1. Bug in `findMax` function:
   - **Issue:** The function returned 0 when the input vector was empty.
   - **Fix:** Updated to return `INT_MIN` (from `<climits>`) instead of 0 to indicate an invalid or empty list.
   
## 2. Bug in `containsNegative` function:
   - **Issue:** The original implementation had an error in the loop condition `i <= numbers.size()`, which would cause an out-of-bounds access.
   - **Fix:** The loop condition was updated to `i < numbers.size()` to avoid accessing invalid indices.

## 3. Bug in `sumRange` function:
   - **Issue:** The `sumRange` function was calculating the sum correctly, so no fix was needed.
   - **Fix:** No changes needed here.
  