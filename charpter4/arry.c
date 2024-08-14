#include <stdio.h>
#include <stdlib.h>
// 初始化数组
void init_arr(int *nums, int size) {
  for (size_t i = 0; i < size; i++) {
    nums[i] = 0;
  }
}
/* 随机访问元素 */
int randomAccess(int *nums, int size) {
  // 在区间 [0, size) 中随机抽取一个数字
  int randomIndex = rand() % size;
  // 获取并返回随机元素
  int randomNum = nums[randomIndex];
  return randomNum;
}
// 向索引index处插入数据num
void insert(int *nums, int size, int num, int index) {
  // 把索引index以及之后的所有元素向后移动一位
  for (size_t i = size - 1; i > index; i--) {
    nums[i] = nums[i - 1];
  }
  // 将num赋值给index处的元素
  nums[index] = num;
}
// 删除索引index处的元素
void removeItem(int *nums, int size, int index) {
  for (size_t i = index; i < size - 1; i++) {
    nums[i] = nums[i + 1];
  }
}
// 遍历数组
void traverse(int *nums, int size) {
  // 通过索引遍历数组
  for (int i = 0; i < size; i++) {
    printf("%d\n", nums[i]);
  }
}
// 查找元素
int find(int *nums, int size, int target) {
  for (size_t i = 0; i < size; i++) {
    if (nums[i] == target)
      return i;
  }
  return -1;
}
// 扩展数组长度
int *extend(int *nums, int size, int enlarge) {
  // 初始化一个扩展长度后的数组
  int *res = (int *)malloc(sizeof(int) * (size + enlarge));
  // 将原数组中的所有元素复制到新数组中
  for (size_t i = 0; i < size; i++) {
    res[i] = nums[i];
  }
  // 初始化拓展后的空间
  for (size_t i = size; i < size + enlarge; i++)
    res[i] = 0;
  // 返回拓展后的新数组
  return res;
}

int main(int argc, char *argv, char *envp) {
  int nums_size = 10;
  int nums[nums_size];
  init_arr(nums, nums_size);
  insert(nums, nums_size, 5, 3);
  // removeItem(nums,nums_size,3);
  traverse(nums, nums_size);
  printf("----- ---- ----\n");
  // printf("%d\n",find(nums,nums_size,5));
  int *new_nums = extend(nums, nums_size, 5);
  for (size_t i = 0; i < 15; i++) {
    new_nums[i] = i;
  }

  traverse(new_nums, 15);
  printf("sizeof nums = %ld\n", sizeof(nums) / sizeof(nums[0]));
  // printf("sizeof new_nums = %ld\n",sizeof(new_nums)/sizeof(new_nums[0]));

  return 0;
}
