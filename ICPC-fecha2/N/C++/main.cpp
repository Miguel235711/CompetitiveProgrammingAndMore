#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

long GetPrime(long n) {
        if (n <= 1) return 1;

        for (long p = 2; ; ++p) {
                if (n%p == 0) {
                        return p;
                }
        }
}

struct Edge {
        long  m, n, d;
};

struct Nodos {
        long M, N, K;
        vector<long> m_nodes;
        vector<long> n_nodes;
        vector<Edge> edges;

        Nodos(vector<long> m_nodes, vector<long> n_nodes, vector<Edge> edges)
         : m_nodes(m_nodes), n_nodes(n_nodes), edges(edges)
        {
                M = m_nodes.size();
                N = n_nodes.size();
                K = edges.size();
        }

        void Solve()
        {       
                for (;;) {
                        long min_m = -1;

                        for (auto &e : edges) {
                                if (e.d <= 0) continue;
                                if (min_m == -1 || e.m < min_m)
                                        min_m = e.m;
                        }
                        
                        if (min_m == -1) {
                                for (long i = 0; i < M; ++i) {
                                        cout << m_nodes[i];
                                        if (i == M-1) cout << endl;
                                        else          cout << " ";
                                }
                                return;
                        }

                        for (auto &e : edges) {
                                if (e.d <= 0) continue;
                                if (e.m == min_m) {
                                        long prime = GetPrime(n_nodes[e.n]);
                                        m_nodes[e.m] = prime;
                                        n_nodes[e.n] /= (pow(prime, e.d));
                                        e.d = 0;
                                }
                        }
                }
        }
};


void
test_case()
{
        long  M, N, K;
        cin >> M >> N >> K;
        vector<long> m_nodes;
        vector<long> n_nodes;
        vector<Edge> edges;
        m_nodes.resize(M, -1);
        n_nodes.resize(N);
        edges.resize(K);

        for (long i = 0; i < N; ++i) {
                cin >> n_nodes[i];
        }
        for (long i = 0; i < K; i++) {
                long m, n, d;
                cin >> m >> n >> d;
                edges[i].m = m-1;
                edges[i].n = n-1;
                edges[i].d = d;
        }

        Nodos nodos(m_nodes, n_nodes, edges);
        nodos.Solve();
}

int
main()
{
	/* main */
        test_case();

        return 0;
}
