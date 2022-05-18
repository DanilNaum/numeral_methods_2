#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;
/*vector<vector<double>> ForwardGauss(vector<vector <double>>& A, vector<double>& B) {
	
}
*/
vector<double>Gaus(vector<vector <double>>& A, vector<double>& B) {
	for (int i = 0; i < A.size(); i++) { //прямой ход Гауса
		double first = A[i][i];
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
			}B[k] -= alpha*B[i];
		}
	}
	
	reverse(A.begin(), A.end());			//переворот массив, эмитация обратного хода гауса 
	reverse(B.begin(), B.end());
	for (int i = 0; i < A.size(); i++) {
		reverse(A[i].begin(), A[i].end());
	}
	for (int i = 0; i < A.size(); i++) {
		double first = A[i][i];
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
	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());
	for (int i = 0; i < A.size(); i++) {
		reverse(A[i].begin(), A[i].end());
	}
	for (int i = 0; i < A.size(); i++) {
		for (int j = 0; j < A[i].size(); j++) {
			cout<<A[i][j]<<" ";
		}
		cout <<" \t |" << B[i] << endl;
	}
	return B;
}

int main() {
	vector<vector<double>>A = { {13., 1., 1.} 
	                           ,{1., 15., 1.} 
	                           ,{1., 1., 17.} };
	vector<double>B = { 15., 17., 19. };
	vector<double>ans = Gaus(A, B);
	cout << "Gauss:" << " ";
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	return 0;
}