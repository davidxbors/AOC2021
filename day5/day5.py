def read(filepath):
    with open(filepath) as fin:
        vents = [x.strip().split(' -> ') for x in fin.readlines()]
        vents = [[(int(x[0].split(',')[0]), int(x[0].split(',')[1])) , (int(x[1].split(',')[0]), int(x[1].split(',')[1]))] for x in vents]
    return vents

def part1():
    vents = read("data/day5")
    result = 0
    for i, vent in enumerate(vents):
        if vent[0][0] == vent[1][0] or vent[0][1] == vent[1][1]:
            for j in range(i):
                # check if lines / cols intersect and with how many points
                # two cols intersect
                if vents[j][0][0] == vents[j][1][0] and vent[0][0] == vent[1][0] and vents[j][0][0] == vent[0][0]:
                    tmp = min(max(vent[0][1], vent[1][1]), max(vents[j][0][1], vents[j][1][1])) - max(min(vent[0][1], vent[1][1]), min(vents[j][0][1], vents[j][1][1]))
                    result += (tmp+1) if tmp >= 0 else 0
                # two lines intersect
                if vents[j][0][1] == vents[j][1][1] and vent[0][1] == vent[1][1] and vents[j][0][1] == vent[0][1]:
                    tmp = min(max(vent[0][0], vent[1][0]), max(vents[j][0][0], vents[j][1][0])) - max(min(vent[0][0], vent[1][0]), min(vents[j][0][0], vents[j][1][0]))
                    result += (tmp+1) if tmp >= 0 else 0
                # line & col intersect
                # check if vent is a line => the other vent must be a col
                if vent[0][1] == vent[1][1] and vents[j][0][0] == vents[j][1][0]:
                    if min(vents[j][0][1], vents[j][1][1]) <= vent[0][1] and vent[0][1] <= max(vents[j][0][1], vents[j][1][1]):
                        if min(vent[0][0], vent[1][0]) <= vents[j][0][0] and vents[j][0][0] <= max(vent[0][0], vent[1][0]):
                            result += 1
                # check if vent is a col => the other vent must be a line
                if vent[0][0] == vent[1][0] and vents[j][0][1] == vents[j][1][1]:
                    if min(vent[0][1], vent[1][1]) <= vents[j][0][1] and vents[j][0][1] <= max(vent[0][1], vent[1][1]):
                        if min(vents[j][0][0], vents[j][1][0]) <= vent[0][0] and vent[0][0] <= max(vents[j][0][0], vents[j][1][0]):
                            result += 1
                
    print(result)

 
def main():
    print("AOC2021 Day5: ")
    print("Part1 => ")
    print("Part2 => ")
    part1()

if __name__ == "__main__":
    main()
