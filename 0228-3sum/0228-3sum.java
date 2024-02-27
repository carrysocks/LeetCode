public class Solution {
    public ArrayList<ArrayList<Integer>> threeSum(int[] num) {
        
        if(num==null||num.length<3)
        return null;
       
        
        ArrayList<ArrayList<Integer>> res= new ArrayList<ArrayList<Integer>>();
        for(int i=0;i<num.length;i++)
        {
         if(num[i]<=0)
         for(int j=i+1;j<num.length;j++)
         if(num[i]+num[j]<=0)
         for(int k=num.length;k>j;k--)
         if(num[i]+num[j]+num[k]==0)
         {
             ArrayList<Integer> ls= new ArrayList<Integer>();
             ls.add(num[i]);
             ls.add(num[j]);
             ls.add(num[k]);
             res.add(ls);
        }
    }
    return res;
}
}