class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
       List<Integer> arr=new ArrayList<>();
       int top=0;
       int bottom=matrix.length-1;
       int left=0;
       int right=matrix[0].length-1;
       // top, bot -> row
       // left, right -> col
       while(top<=bottom && left<=right){

          // left to right
          for(int i=left;i<=right;i++){
            arr.add(matrix[top][i]);
          }
          top++;
          //top to bottom
          for(int i=top;i<=bottom;i++){
            arr.add(matrix[i][right]);
          }
          right--;
          if(top>bottom || left>right){
            break;
          }
          //right to left
          for(int i=right;i>=left;i--){
            arr.add(matrix[bottom][i]);
          }
          bottom--;
          // bottom to top
          for(int i=bottom;i>=top;i--){
            arr.add(matrix[i][left]);
          }
          left++;
       }
       return arr;
    }
}