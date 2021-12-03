def get_freq(lines):
    fr = [0] * (len(lines[0])-1)
    for line in lines:
        for i in range(len(line)-1):
            fr[i] += int(line[i])
    for i, freq in enumerate(fr):
        if freq > len(lines) / 2:
            fr[i] = 1
        elif freq == len(lines)/2 and len(lines) % 2 == 0:
            fr[i] = 1
        else:
            fr[i] = 0
    return fr

def part1():
    with open("data/day3") as fin:
        lines = fin.readlines()
        fr = get_freq(lines)
        gamma = int(''.join(str(f) for f in fr), 2)
        epsilon = int(''.join(str(1) if f == 0 else str(0) for f in fr), 2)
        return gamma * epsilon

def oxygen(new_list):
    fr = get_freq(new_list)
    for i in range(len(fr)):
        new_list = [x for x in new_list if int(x[i]) == fr[i]]
        if len(new_list) == 1:
            return int(new_list[0], 2)
        fr = get_freq(new_list)

def co2(new_list):
    fr = get_freq(new_list)
    for i in range(len(fr)):
        new_list = [x for x in new_list if int(x[i]) != fr[i]]
        if len(new_list) == 1:
            return int(new_list[0], 2)
        fr = get_freq(new_list)
    
def part2():
    with open("data/day3") as fin:
        lines = fin.readlines()
    return oxygen(lines) * co2(lines)

def main():
    print("AOC2021 Day 3 **")
    print("Part 1 result = " + str(part1()))
    print("Part 2 result = " + str(part2()))
        
if __name__ == "__main__":
    main()
