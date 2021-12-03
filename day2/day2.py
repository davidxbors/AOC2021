def part1():
   with open("data/day2") as fin:
      commands = [(line.split(' ')[0], line.split(' ')[1].strip()) for line in fin.readlines()]
      horizontal_travel = lambda cmds: (sum(int(cmd[1]) for cmd in cmds if cmd[0][0] == 'f'))
      depth_change = lambda cmd: -int(cmd[1]) if cmd[0][0] == 'u' else int(cmd[1]) if cmd[0][0] == 'd' else 0 
      depth_travel = lambda cmds: (sum(depth_change(cmd) for cmd in cmds))
      return horizontal_travel(commands) * depth_travel(commands)

def part2():
    with open("data/day2") as fin:
        commands = [(line.split(' ')[0], line.split(' ')[1].strip()) for line in fin.readlines()]
        horizontal = depth = aim = 0
        for cmd in commands:
            if cmd[0][0] == 'f':
                horizontal += int(cmd[1])
                depth += int(cmd[1]) * aim
            elif cmd[0][0] == 'u':
                aim -= int(cmd[1])
            else:
                aim += int(cmd[1])

        return horizontal * depth

def main():
   print("Day2 AOC 2021 **")
   print("Result of part1: " + str(part1()))
   print("Result of part2: " + str(part2()))

if __name__ == "__main__":
    main()
