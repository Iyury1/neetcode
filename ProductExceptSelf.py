from typing import List

# def productExceptSelf(nums: List[int]) -> List[int]:
#     product = 1
#     nz_product = 1
#     for num in nums:
#         product = product * num
#         if num != 0:
#             nz_product = nz_product * num
    
#     out = []

#     for num in nums:
#         print(num)
#         if num == 0:
#             out.append(nz_product)
#         else:
#             out.append(int(product/num))

#     return out

import numpy as np
def productExceptSelf(nums: List[int]) -> List[int]:
    prefix = np.ones(len(nums), dtype=int)
    for i in range(1, len(nums)):
        prefix[i] = prefix[i-1] * nums[i-1]

    suffix = np.ones(len(nums), dtype=int)
    for i in range(len(nums)-1, 0, -1):
        suffix[i-1] = suffix[i] * nums[i]

    return (prefix*suffix).tolist()

if __name__ == "__main__":
    print(productExceptSelf([-1,0,1,2,3]))