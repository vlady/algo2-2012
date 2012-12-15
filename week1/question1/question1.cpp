#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;
typedef vector<pair<LL, LL> > JobList; 

int num_jobs;
JobList jobs; // (weight, length)

LL evaluate_jobs(const JobList& jobs) {
  int num_jobs = jobs.size();
  LL sum_lengths = 0;
  LL weighted_sum = 0;
  for (int idx = 0; idx < num_jobs; ++idx) {
    sum_lengths += jobs[idx].second;
    weighted_sum += jobs[idx].first * sum_lengths;
  }
  return weighted_sum;
}

void read_input() {
  freopen("jobs.txt", "r", stdin);
  cin >> num_jobs;
  jobs.clear();

  for (int idx = 0; idx < num_jobs; ++idx) {
    int weight, length;
    cin >> weight >> length;
    jobs.push_back(make_pair(weight, length));
  }
  fclose(stdin);
}

int main() {
  read_input();
  cout << evaluate_jobs(jobs) << '\n';
  return 0;  
}
