#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// //列表实现
// 初始容量：选取一个合理的数组初始容量。在本示例中，我们选择 10 作为初始容量。
// 数量记录：声明一个变量 size ，用于记录列表当前元素数量，
// 并随着元素插入和删除实时更新。根据此变量，我们可以定位列表尾部，以及判断是否需要扩容。
// 扩容机制：若插入元素时列表容量已满，则需要进行扩容。先根据扩容倍数创建一个更大的数组，
// 再将当前数组的所有元素依次移动至新数组。在本示例中，我们规定每次将数组扩容至之前的
// 2 倍
/*列表类*/
typedef struct {
  int *arr;        // 数组(存储列表元素)
  int capacity;    // 列表容量
  int size;        // 列表大小
  int extendRatio; // 列表每次扩容的倍数
} Mylist;
// 构造函数
Mylist *newMylist() {
  Mylist *nums = malloc(sizeof(Mylist));
  nums->capacity = 10;
  nums->arr = malloc(sizeof(int) * nums->capacity);
  nums->size = 0;
  nums->extendRatio = 2;
  return nums;
}
// 析构函数
void delMylist(Mylist *nums) {
  free(nums->arr);
  free(nums);
}
// 获取列表长度
int size(Mylist *nums) { return nums->size; }
// 获取列表容量
int capcaity(Mylist *nums) { return nums->capacity; }
// 访问元素
int get(Mylist *nums, int index) {
  assert(index > 0 && index < nums->size);
  return nums->arr[index];
}
// 更新元素
void set(Mylist *nums, int index, int num) {
  assert(index > 0 && index < nums->size);
  nums->arr[index] = num;
}
// 在尾部添加元素
void add(Mylist *nums, int num) {
  if (size(nums) == capcaity(nums)) {
    extendCapacity(nums); // 扩容
  }
  nums->arr[size(nums)] = num;
  nums->size++;
}

// 在中间添加元素
void insert(Mylist *nums, int index, int num) {
  assert(index > 0 && index < size(nums));
  // 元素数量超出容量时,触发扩容机制
  if (size(nums) == capcaity(nums)) {
    extendCapacity(nums);
  }
  for (size_t i = size(nums); i < index; i--) {
    nums->arr[i] = nums->arr[i - 1];
  }
  nums->arr[index] = num;
  nums->size++;
}

// 删除元素
// stdio.h 占用了remove关键词
void removeItem(Mylist *nums, int index) {
  assert(index > 0 && index < size(nums));
  int num = nums->arr[index];
  for (int i = index; i < size(nums) - 1; i++) {
    nums->arr[i] = nums->arr[i + 1];
  }
  nums->size--;
  return num;
}
// 列表扩容
void extendCapacity(Mylist *nums) {
  // 分配空间
  int newCapacity = capcaity(nums) * nums->extendRatio;
  int *extend = (int *)malloc(sizeof(int) * newCapacity);
  int *temp = nums->arr;
  // 拷贝旧数据到新数据
  for (size_t i = 0; i < size(nums); i++) {
    extend[i] = nums->arr[i];
  }
  // 释放旧数据
  free(temp);
  // 更新新数据
  nums->arr = extend;
  nums->capacity = newCapacity;
}
// 将列表转换为Array用于打印
int *toArry(Mylist *nums) { return nums->arr; }
