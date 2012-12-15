#include <iostream>
#include <vector>

using namespace std;

typedef vector<pair<int, int> > JobList; 

int num_jobs;
JobList jobs; // (weight, length)

int evaluate_jobs(const JobList& jobs) {
  int num_jobs = jobs.size();
  int sum_lengths = 0;
  int weighted_sum = 0;
  for (int idx = 0; idx < num_jobs; ++idx) {
    sum_lengths += jobs[idx].second;
    weighted_sum += jobs[idx].first * sum_lengths;
  }
  return weighted_sum;
}

int main() {
  freopen("jobs.txt", "r", stdin);
  fclose(stdin);
  return 0;  
}
