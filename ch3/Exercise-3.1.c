#include <stdio.h>
#include <time.h>

int binsearch1(int x, int inc_sorted_arr[], int num_elems);
int binsearch2(int x, int inc_sorted_arr[], int num_elems);

int main() {
  int test[] = { 1, 3, 5, 7, 9, 11, 13, 15, 17 };
  int i;

  clock_t start = clock();
  for (i=0; i < 10000000; i++)
    binsearch1(2, test, 8);
  clock_t time = clock() - start;
  printf("Two inner tests took %lu clock time\n", time);

  start = clock();
  for (i=0; i < 10000000; i++)
    binsearch2(2, test, 8);
  time = clock() - start;
  printf("One inner test took %lu clock time\n", time);

  return 0;
}

// find x in v[0] <= v[1] <= ... <= v[n-1]
int binsearch1(int x, int v[], int n) {
  int low = 0, high = n-1, mid;

  while (low <= high) {
    mid = (low+high)/2;
    if (x < v[mid])
      high = mid - 1;
    else if (x > v[mid])
      low = mid + 1;
    else  // found match
      return mid;
  }
  return -1;  // no match
}

// one test inside loop is faster
int binsearch2(int x, int v[], int n) {
  int low = 0, high = n-1, mid;

  mid = (low+high)/2;
  while (low <= high && x != v[mid]) {
    if (x < v[mid])
      high = mid - 1;
    else
      low = mid + 1;
    mid = (low+high)/2;
  }

  if (x == v[mid])
    return mid;
  else
    return -1;
}
