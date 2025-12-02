//m = tamanho do padrão, n = tamanho da base
void kmpPreprocess(int m, int n, string P, vector<int>& b) {
// call this before calling kmpSearch()
    int i = 0, j = -1; b[0] = -1;
    // starting values
    while (i < m) {
        // pre-process the pattern string P
        while (j >= 0 && P[i] != P[j]) j = b[j]; // different, reset j using b
        i++; j++;
        // if same, advance both pointers
        b[i] = j; // observe i = 8, 9, 10, 11, 12, 13 with j = 0, 1, 2, 3, 4, 5
    } 
}
// in the example of P = "SEVENTY SEVEN" above
void kmpSearch(int n, int m, string T, string P, vector<int>& b, int& resp) {
    // this is similar as kmpPreprocess(), but on string T
    int i = 0, j = 0;
    // starting values
    while (i < n) {
        // search through string T
        while (j >= 0 && T[i] != P[j]){
            j = b[j];
        } // different, reset j using b
        i++; j++;
        // if same, advance both pointers
        if (j == m) {
            // a match found when j == m
            resp++;
            j = b[j];
            // prepare j for the next possible match
        } 
    } 
}


//Sufix array
void constructSA() {
  // this version can go up to 100000 characters
  int i, k, r;
  for (i = 0; i < n; i++) RA[i] = T[i];
  // initial rankings
  for (i = 0; i < n; i++) SA[i] = i;
  // initial SA: {0, 1, 2, ..., n-1}
  for (k = 1; k < n; k <<= 1) {
    // repeat sorting process log n times
    countingSort(k); // actually radix sort: sort based on the second item
    countingSort(0);
    // then (stable) sort based on the first item
    tempRA[SA[0]] = r = 0;
    // re-ranking; start from rank r = 0
    for (i = 1; i < n; i++)
    // compare adjacent suffixes
    tempRA[SA[i]] = // if same pair => same rank r; otherwise, increase r
    (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) ? r : ++r;
    for (i = 0; i < n; i++)
    // update the rank array RA
    RA[i] = tempRA[i];
    if (RA[SA[n-1]] == n-1) break;
    // nice optimization trick
  }
}

int main() {
  n = (int)strlen(gets(T));
  // input T as per normal, without the ‘$’
  T[n++] = ’$’;
  // add terminating character
  constructSA();
  for (int i = 0; i < n; i++) printf("%2d\t%s\n", SA[i], T + SA[i]);
} // return 0;


void computeLCP() {
  int i, L;
  Phi[SA[0]] = -1;
  // default value
  for (i = 1; i < n; i++)
  // compute Phi in O(n)
  Phi[SA[i]] = SA[i-1];
  // remember which suffix is behind this suffix
  for (i = L = 0; i < n; i++) {
    // compute Permuted LCP in O(n)
    if (Phi[i] == -1) { PLCP[i] = 0; continue; }
    // special case
    while (T[i + L] == T[Phi[i] + L]) L++;
    // L increased max n times
    PLCP[i] = L;
    L = max(L-1, 0);
    // L decreased max n times
  }
  for (i = 0; i < n; i++)
  // compute LCP in O(n)
  LCP[i] = PLCP[SA[i]];
  // put the permuted LCP to the correct position
}


#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100010

char T[MAX_N];
int n;
int RA[MAX_N], temp_RA[MAX_N];
int SA[MAX_N], temp_SA[MAX_N];
int c[MAX_N];

void countingSort(int k) {
    int i, sum, maxi = max(300, n);
    memset(c, 0, sizeof(int) * maxi); // CORREÇÃO 1: zerar c[]

    for (i = 0; i < n; i++) {
        c[i + k < n ? RA[i + k] : 0]++;
    }
    for (i = sum = 0; i < maxi; i++) {
        int t = c[i];
        c[i] = sum;
        sum += t;
    }

    for (i = 0; i < n; i++) {
        temp_SA[c[SA[i] + k < n ? RA[SA[i] + k] : 0]++] = SA[i];
    }

    for (i = 0; i < n; i++) {
        SA[i] = temp_SA[i];
    }
}

void constructSA() {
    int i, k, r;
    for (i = 0; i < n; i++) { RA[i] = T[i]; }
    for (i = 0; i < n; i++) { SA[i] = i; }
    for (k = 1; k < n; k <<= 1) {
        countingSort(k);
        countingSort(0);
        temp_RA[SA[0]] = r = 0;
        for (i = 1; i < n; i++) {
            bool sameRank1 = (RA[SA[i]] == RA[SA[i-1]]);
            bool sameRank2 =
                (SA[i] + k < n ? RA[SA[i] + k] : -1) ==
                (SA[i-1] + k < n ? RA[SA[i-1] + k] : -1);
            temp_RA[SA[i]] = (sameRank1 && sameRank2 ? r : ++r);
        }
        for (i = 0; i < n; i++) {
            RA[i] = temp_RA[i];
        }
        if (RA[SA[n-1]] == n-1) { break; }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> T[i];
    }
    T[n++] = '$'; // sentinel menor que qualquer caractere
    constructSA();
    for (int i = 0; i < n; i++) {
        cout << SA[i] << " " << (T + SA[i]) << "\n";
    }

    return 0;
}
