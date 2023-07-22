class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        List=[]
        for i in range(0,numRows):
            List1=[]
            for j in range(i+1):
                if j==0 or j==i:
                    List1.append(1)
                else:
                    List1.append(List[i-1][j-1]+List[i-1][j])
            List.append(List1)
        return List