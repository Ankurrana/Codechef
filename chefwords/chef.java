import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
	public static double[][] powerMatrix(double[][] m, long exp){
		if(exp==1) return m;
		if(exp==2) return matrixMultiplication(m,m);
		double[][] subMatrix=powerMatrix(m,exp/2);
		double[][] result=matrixMultiplication(subMatrix,subMatrix);
		if(exp%2==1) result=matrixMultiplication(result,m);
		return result;
	}
	
	public static double[][] matrixMultiplication(double[][] m1, double[][] m2){
		if(m1[0].length!=m2.length) return null;
		int rows=m1.length,cols=m2[0].length;
		double[][] result=new double[rows][cols];
		for(int i=0;i<rows;i++) for(int j=0;j<cols;j++) result[i][j]=0;
		for(int i=0;i<rows;i++)
			for(int j=0;j<cols;j++)
				for(int k=0;k<m1[0].length;k++)
					result[i][j]+=(m1[i][k]*m2[k][j]);
		return result;
	}
	
	public static void printMatrix(double[][] m){
		int rows=m.length,cols=m[0].length;
		System.out.print("  ");
		for(int i=0;i<26;i++) System.out.print((char)('a'+i)+"     ");
		for(int i=0;i<rows;i++){
			for(int j=0;j<cols;j++){
				System.out.print((char)('a'+i)+" "+String.format("%.2f",m[i][j])+" ");		
			}
			System.out.println();
		}
	}
	
	public static void solve() throws Exception {
		StringBuilder sb = new StringBuilder();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		while(t-->0){
			String[] input=br.readLine().split(" ");
			int n=Integer.parseInt(input[0]);
			long k=Long.parseLong(input[1]);
			String chefsWord=br.readLine();
			double[][] probability=new double[26][26];
			for(int i=0;i<26;i++){
				String[] input2=br.readLine().split(" ");
				for(int j=0;j<26;j++){
					probability[i][j]=Double.parseDouble(input2[j]);
				}
			}
			double totalProbability=0;
			double[][] probabilityForKClaps=powerMatrix(probability, k);
			//printMatrix(probabilityForKClaps);
			for(int i=0;i<n;i++){
				String word=br.readLine();
				if(word.length()==chefsWord.length()){
					double tempProbability=1;
					for(int j=0;j<word.length();j++)
						tempProbability*=probabilityForKClaps[chefsWord.charAt(j)-'a'][word.charAt(j)-'a'];
					totalProbability+=tempProbability;
				}
			}
			if(totalProbability>1)sb.append("1\n");
			else sb.append(String.format("%.15f",totalProbability)+"\n");
		}
		System.out.println(sb.toString());
	}
    public static void main(String args[] ) throws Exception {
        solve();
    }
}