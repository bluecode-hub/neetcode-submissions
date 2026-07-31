class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        with_zero=1
        without_zero=1
        count=0
        for i in nums:
            if i==0:
                count=count+1
            with_zero=with_zero*i
            if i!=0:
                without_zero=without_zero*i
        flag=False
        list=[]
        if count>=2:
            flag=True
        for i in nums:
            if count==len(nums):
                list.append(0)
            elif flag==True:
                list.append(0)
            elif i!=0:
                list.append(int(with_zero/i))
            else:

                list.append(without_zero)
        return list

        