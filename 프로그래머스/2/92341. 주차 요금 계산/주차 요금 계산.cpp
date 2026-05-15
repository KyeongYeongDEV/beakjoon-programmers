#include <string>
#include <vector>
#include <map>
#include <cmath> // ceil 사용

using namespace std;

// 시간을 분 단위 정수로 변환하는 함수
int changeTime(string time) {
    int hh = stoi(time.substr(0, 2));
    int mm = stoi(time.substr(3, 2));
    return hh * 60 + mm;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, int> m_time;  // 차량번호 : 입차 시간(분)
    map<string, int> m_total; // 차량번호 : 누적 주차 시간(분)
    
    // 1. 입/출차 기록 처리
    for (string record : records) {
        // 형식: "05:34 5961 IN"
        int time = changeTime(record.substr(0, 5));
        string car_num = record.substr(6, 4);
        string status = record.substr(11); // "IN" 또는 "OUT"
        
        if (status == "IN") {
            m_time[car_num] = time;
        } else {
            // 출차 시 누적 시간에 (현재 시간 - 입차 시간) 더하기
            m_total[car_num] += (time - m_time[car_num]);
            m_time.erase(car_num); // 입차 목록에서 제거
        }
    }
    
    // 2. 출차 기록이 없는 차량 처리 (23:59 기준)
    int last_time = changeTime("23:59");
    for (auto const& [carNum, inTime] : m_time) {
        m_total[carNum] += (last_time - inTime);
    }
    
    // 3. 최종 요금 정산 (map은 차량 번호 순으로 정렬됨)
    for (auto const& [carNum, totalMinutes] : m_total) {
        int baseTime = fees[0];
        int baseFee = fees[1];
        int unitTime = fees[2];
        int unitFee = fees[3];
        
        int finalFee = baseFee;
        
        // 기본 시간을 초과한 경우만 추가 요금 계산
        if (totalMinutes > baseTime) {
            finalFee += ceil((double)(totalMinutes - baseTime) / unitTime) * unitFee;
        }
        
        answer.push_back(finalFee);
    }
    
    return answer;
}