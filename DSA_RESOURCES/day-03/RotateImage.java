class Solution {
    public void rotate(int[][] matrix) {
        // transpose 
        // reverse each row
        for(int i=0;i<matrix.length;i++){
            for(int j=i+1;j<matrix[0].length;j++){
                int t= matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=t;
            }
        }
        for(int i=0;i<matrix.length;i++){
            int start=0;
            int end=matrix[0].length-1;
            while(start<end){
                int t=matrix[i][start];
                matrix[i][start]=matrix[i][end];
                matrix[i][end]=t;
                start++;
                end--;
            }
        }

    }
}