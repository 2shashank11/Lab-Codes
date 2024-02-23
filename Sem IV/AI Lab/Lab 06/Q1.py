import math
import random 

def mountain_function(x):
	return -(x**2) + 5*x + 25

def hill_climb():
	current = random.uniform(-10,10)

	while(True):
		current_val = mountain_function(current)

		neighbors = [current + d for d in [-0.1,0.1]]
		#make bounds
		neighbors = [max(min(n , 10),-10) for n in neighbors]

		best_neighbor = max(neighbors , key = mountain_function)
		best_neighbor_val = mountain_function(best_neighbor)

		if best_neighbor_val > current_val:
			current = best_neighbor
		else:
			break
	return current , mountain_function(current)

peak , peak_val = hill_climb()
print(f"peak value {peak_val}\nfound at peak {peak}")
