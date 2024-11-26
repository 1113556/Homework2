#蔡宗修
#1113556
#11/22
import heapq

def merge_k_sorted_arrays(k, arrays):
    # Min Priority Queue
    min_heap = []
    
    # Initialize the heap with the first element of each array
    for array_idx in range(k):
        if arrays[array_idx]:  # Check if the array is non-empty
            heapq.heappush(min_heap, (arrays[array_idx][0], array_idx, 0))
    
    result = []
    
    # Process the Min Priority Queue
    while min_heap:
        # Extract the smallest element from the heap
        value, array_idx, element_idx = heapq.heappop(min_heap)
        result.append(value)
        
        # If the array has more elements, add the next element to the heap
        if element_idx + 1 < len(arrays[array_idx]):
            next_value = arrays[array_idx][element_idx + 1]
            heapq.heappush(min_heap, (next_value, array_idx, element_idx + 1))
    
    return result

# Input
k = int(input("Typed here: "))
arrays = []
for _ in range(k):
    arrays.append(list(map(int, input().strip().split())))

# Merge the arrays
merged_array = merge_k_sorted_arrays(k, arrays)

# Output
print(", ".join(map(str, merged_array)))

