class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        total = 0      # Total gas surplus/deficit over the entire trip
        tank = 0       # Current gas in tank from the chosen start point
        start = 0      # Candidate starting station

        for i in range(len(gas)):
            gain = gas[i] - cost[i]

            total += gain
            tank += gain

            # Current start cannot reach the next station
            if tank < 0:
                start = i + 1
                tank = 0

        # Not enough gas overall to complete the circuit
        if total < 0:
            return -1

        return start