// not solved -> really hard problem -> only understood the intuition

class Solution {
  static constexpr int MOD = 1'000'000'007;

  // problem inputs
  vector<int> nums;
  int n;      // nums.size()
  int totalM; // original m (max selections)

  // comb[m_rem][count] modulo MOD
  vector<vector<int>> comb;

  // memo[m_rem][k_rem][i][carry] -> -1 if unknown else value
  // dimensions allocated in magicalSum()
  vector<vector<vector<vector<int>>>> memo;

  // fast modular exponentiation
  long long modPow(long long a, int e) {
    long long res = 1;
    a %= MOD;
    while (e > 0) {
      if (e & 1) res = (res * a) % MOD;
      a = (a * a) % MOD;
      e >>= 1;
    }
    return res;
  }

  // build combination table C[0..m][0..m]
  vector<vector<int>> buildComb(int m) {
    vector<vector<int>> c(m + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= m; ++i) {
      c[i][0] = 1;
      for (int j = 1; j <= i; ++j) {
        long long v = c[i - 1][j];
        v += c[i - 1][j - 1];
        if (v >= MOD) v -= MOD;
        c[i][j] = (int)v;
      }
    }
    return c;
  }

  // DP recursion
  int dp(int m_rem, int k_rem, int i, int carry) {
    if (m_rem < 0 || k_rem < 0) return 0;
    // quick pruning: even if all remaining picks create set bits,
    // we cannot reach k_rem if m_rem + popcount(carry) < k_rem
    if (m_rem + __builtin_popcount((unsigned)carry) < k_rem) return 0;

    if (m_rem == 0) {
      // no more picks: remaining set bits are the popcount of carry
      return (__builtin_popcount((unsigned)carry) == k_rem) ? 1 : 0;
    }
    if (i == n) return 0; // no more indices to choose from

    int &memoRef = memo[m_rem][k_rem][i][carry];
    if (memoRef != -1) return memoRef;

    long long ans = 0;
    // choose count copies of index i (0..m_rem)
    for (int count = 0; count <= m_rem; ++count) {
      long long ways = comb[m_rem][count];            // C(m_rem, count)
      long long powTerm = modPow(nums[i], count);     // nums[i]^count % MOD
      long long contribution = (ways * powTerm) % MOD;

      int newCarry = carry + count;
      int lowBit = newCarry & 1;
      int nextCarry = newCarry >> 1;

      int sub = dp(m_rem - count, k_rem - lowBit, i + 1, nextCarry);
      if (sub) {
        ans += contribution * sub;
        if (ans >= (1LL<<62)) ans %= MOD; // occasional reduction to avoid overflow
      }
    }

    ans %= MOD;
    memoRef = (int)ans;
    return memoRef;
  }

public:
  // LeetCode signature: magicalSum(m, k, nums)
  int magicalSum(int m, int k, vector<int>& nums_) {
    nums = nums_;
    n = (int)nums.size();
    totalM = m;

    // build combination table up to m
    comb = buildComb(m);

    // allocate memo: m_rem:0..m, k_rem:0..k, i:0..n, carry:0..m
    memo.assign(m + 1,
                vector<vector<vector<int>>>(k + 1,
                  vector<vector<int>>(n + 1,
                    vector<int>(m + 1, -1))));

    return dp(m, k, 0, 0);
  }
};
