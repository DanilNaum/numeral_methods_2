#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;
vector<vector<double>> ForwardGauss(vector<vector <double>>& A, bool p) {
	vector<double> B = A[A.size()-1];
	A.erase(A.end()-1);
	for (int i = 0; i < A.size(); i++) { //������ ��� �����
		double first = A[i][i];
		if (p) {
			for (int k = i + 1; k < A.size(); k++) {
				if (first < A[k][i]) {
					first = A[k][i];
					vector<double> tmp_v = A[i];
					A[i] = A[k];
					A[k] = tmp_v;
					double tmp_d = B[i];
					B[i] = B[k];
					B[k] = tmp_d;
				}
			}
		}
		B[i] /= first;
		for (int j = 0; j < A[i].size(); j++) {
			A[i][j] /= first;

		}
		for (int k = i + 1; k < A.size(); k++) {
			double alpha = 0;
			for (int j = 0; j < A[i].size(); j++) {
				if (alpha == 0)
					alpha = A[k][i];
				A[k][j] -= A[i][j] * alpha;
			}B[k] -= alpha * B[i];
		}
	}
	
	reverse(A.begin(), A.end());			//��������� ������, �������� ��������� ���� ����� 
	reverse(B.begin(), B.end());
	for (int i = 0; i < A.size(); i++) {
		reverse(A[i].begin(), A[i].end());
	}
	A.push_back(B);
	return A;
}

vector<double>Gauss(vector<vector <double>> A, vector<double> B) {
	A.push_back(B);
	A = ForwardGauss(A,1);
	A = ForwardGauss(A,0);
	for (int i = 0; i < A.size()-1; i++) {
		for (int j = 0; j < A[i].size(); j++) {
			cout<<A[i][j]<<" ";
		}
		cout <<" \t |" << A[A.size()-1][i] << endl;
	}
	return A[A.size() - 1];
}

double norm_v(vector<double> V) {
	double ans = 0;
	for (int i = 0; i < V.size(); i++) {
		ans += pow(V[i],2);
	}
	return ans;
}

vector<double>Zeyidey(vector<vector <double>> A, vector<double> B) {
	vector<double> x(B.size(), 0), x_prew(B.size(), -10000);
	for (int i = 0; i < A.size(); i++) {
		for (int j = 0; j < A[i].size(); j++) {
			if (i != j) A[i][j] /= -A[i][i];
		}
		B[i] /= A[i][i];
		A[i][i] = 0;
	}
	
	while (abs(norm_v(x) - norm_v(x_prew)) > 1e-3) {
		x_prew = x;
		for (int i = 0; i < x.size(); i++) {
			x[i] = 0;
			for (int j = 0; j < x.size(); j++) 
				x[i] += x[j] * A[i][j];
			x[i] += B[i];
		}
	}
	return x;
}
vector<vector<double>> operator*(double x,vector<vector<double>>M) {
	for (int i = 0; i < M.size(); i++) {
		for (int j = 0; j < M[i].size(); j++) {
			M[i][j] *= x;
		}
	}
	return M;
}

vector<vector<double>> operator+(vector<vector<double>>A, vector<vector<double>>B) {
	if (A.size() != B.size()) {
		for (int i = 0; i < A.size(); i++) {
			for (int j = 0; j < A[i].size(); j++) {
				A[i][j] += B[i][j];
			}
		}
		return A;
	}
	return;
}

int main() {
	vector<vector<double>>A = { {13., 1., 1.} 
	                           ,{1., 15., 1.} 
	                           ,{1., 1., 17.} };
	vector<double>B = { 15., 17., 19. };
	vector<double>ans = Gauss(A, B);
	cout << "Gauss:" << " ";
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	ans = Zeyidey(A, B);
	cout << "\nZeyidey:" << " ";
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	/*vector<vector<double>>A;
	vector<double>B;
	A = 
	vector<double>ans = Gauss(A, B);
	cout << "Gauss:" << " ";
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	ans = Zeyidey(A, B);
	cout << "\nZeyidey:" << " ";
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}*/
	return 0;
}