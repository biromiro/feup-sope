# Deadlock

- Each philosopher picks up the left fork and waits until it can pick up the right fork. There will be no available right forks as all philosophers have a left fork picked up, and a deadlock occurs.

# Livelock

- If a philosopher picks up the forks, puts them down and thinks way too fast for the waiting philosopher to his right or left to pick up the fork he was waiting for, those philosophers might enter the state of starvation as the algorithm will allow one philosopher to continually evolve while the others will be starting and will never get access to the critical zone (there is no 'fairness' to the algorithm, no concept of priority).
