# Results for the sorting project

### On randomized unsorted vectors
* The original quick sort with both good and bad pivots took the same amount of time to complete. However, it took more time for them to complete than the respective in-place quick sorts
* The in-place quick sort with the good and bad pivots both took around the same amount of time to complete

### On sorted vectors
* The in-place quick sort with the bad pivot took a significant amount of time more than the in-place quick sort with a good pivot
  * ex: bad in-place had a time of 1078 vs. good in-place had a time of 1 (list of size 25000)
* the original quick sort with the bad pivot would allocate too much memory when the size of the list became too large. The program is terminated as a result.

### General Notes
* Merge sort took longer on smaller vectors but eventually became faster than the original quick sort as the size of the vector increased.
* The in-place quick sort with a good pivot was always faster than the merge sort
* merge sort took the same amount of time to complete on both randomized and sorted vectors, demonstrating its consistency
