# I generated this list in part1 along with the number of beacons

scanners = [[0, 0, 0], [-62, -53, 1206], [-1294, -101, 1155], [-1281, 1232, 1114], [-48, 69, 2247], [-100, 21, 3416], [-98, -1296, 2399], [-139, -1192, 3578], [26, 57, 4708], [-118, -2462, 2293], [26, -2408, 3603], [-122, -1177, 4698], [1221, 68, 4633], [-1334, -13, 4750], [-1343, -2449, 3420], [1061, -2385, 3500], [36, -2327, 4698], [-46, -1264, 5830], [-1283, -1317, 4793], [-1339, -89, 5953], [-1320, 1154, 4747], [1101, -2397, 4724], [-1186, -1165, 5986], [-1332, 1189, 3446], [-1316, -1136, 7025]]

largest = 0

# Somehow I got this wrong, 15443 is the wrong answer, it is too high
# The real answer is 9621, I had a plus sign instead of a minus at ln11, Col 129
for i in range(len(scanners)):
    for j in range(i+1, len(scanners), 1):
        largest = max(largest, abs(scanners[i][0] - scanners[j][0]) + abs(scanners[i][1] - scanners[j][1]) + abs(scanners[i][2] - scanners[j][2]))

print(largest)