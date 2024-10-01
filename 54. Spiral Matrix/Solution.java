class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        int m=matrix.length;
        int n = matrix[0].length;
        int top=0,left=0,right=n-1,bottom=m-1;
        List<Integer> list = new ArrayList<>();
        while(top<=bottom && left<=right){
            int i=left;
            while(i<=right){
                list.add(matrix[top][i]);
                i++;
            }
            top++;
            i=top;
            while(i<=bottom){
                list.add(matrix[i][right]);
                i++;
            }
            right--;
            if(top<=bottom){
                i = right;
                while(i>=left){
                    list.add(matrix[bottom][i]);
                    i--;
                }
                bottom--;
                i=bottom;
                while(left<=right && i>=top){
                    list.add(matrix[i][left]);
                    i--;
                }
                left++;
            }
            
        }
        return list;
    }
}