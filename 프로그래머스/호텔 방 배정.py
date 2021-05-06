# recursive
import sys
sys.setrecursionlimit(10000000)


def solution(k, room_number):
    def find_vacancy(room_num):
        if room_num not in rooms:
            rooms[room_num] = room_num + 1
            return room_num
        else:
            next_vacancy = find_vacancy(rooms[room_num])
            rooms[room_num] = next_vacancy + 1
            return next_vacancy

    answer = []
    rooms = {}

    for room in room_number:
        answer.append(find_vacancy(room))

    return answer


# iterative
def solution(k, room_number):
    answer = []
    rooms = {}

    for room_requested in room_number:
        room = room_requested
        visit = [room]
        
        while room in rooms:
            room = rooms[room]
            visit.append(room)
        answer.append(room)
        
        for j in visit:
            rooms[j] = room + 1
    
    return answer
