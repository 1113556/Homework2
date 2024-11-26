import heapq

def schedule_tasks(N, tasks):
    # Step 1: Sort tasks based on profit in descending order
    tasks.sort(key=lambda x: -x[0])  # Sort by profit (descending)
    
    # Step 2: Create a max heap and a list to track used slots
    max_deadline = max(task[1] for task in tasks)  # Find the maximum deadline
    used_slots = [False] * (max_deadline + 1)  # Track used slots
    max_profit = 0
    scheduled_tasks = []
    
    for profit, deadline in tasks:
        # Find the latest available slot (starting from the deadline)
        for slot in range(min(deadline, max_deadline), 0, -1):
            if not used_slots[slot]:  # Slot is free
                used_slots[slot] = True
                max_profit += profit
                scheduled_tasks.append(profit)
                break  # Move to the next task
    
    return max_profit, scheduled_tasks

# Input
N = int(input("Enter number of tasks: "))
tasks = []
for _ in range(N):
    profit, deadline = map(int, input("Enter profit and deadline: ").split())
    tasks.append((profit, deadline))

# Process and Output
max_profit, scheduled_tasks = schedule_tasks(N, tasks)
print(f"Maximum Profit: {max_profit}")
print(f"Scheduled Tasks: {scheduled_tasks}")
