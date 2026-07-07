class Solution {
    public int calTotalHrs(int[] piles,int speed){
        int totalHrs=0;
        for(int i=0;i<piles.length;i++){
            totalHrs+=Math.ceil((double)piles[i]/(double)speed 
            );
        }
        return totalHrs;
    }
    public int findMax(int[] piles){
        int maxi=Integer.MIN_VALUE;
        for(int i=0;i<piles.length;i++){
            maxi=Math.max(maxi,piles[i]);
        }
        return maxi;
    }
    public int minEatingSpeed(int[] piles, int h) {
        int n=piles.length;
        int low=1;
        int high=findMax(piles);
        while(low<=high){
            int mid=(low+high)/2;
            int totalHrs=calTotalHrs(piles,mid);
            if(totalHrs<=h){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;

        
    }
}