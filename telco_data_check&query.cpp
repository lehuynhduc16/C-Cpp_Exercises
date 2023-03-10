/*
Một nhà mạng muốn thực hiện truy vấn dữ liệu log lịch sử cuộc gọi trong ngày, dữ liệu log này được format dạng:
call <from_number> <to_number> <date> <from_time> <end_time>
Ý nghĩa của các trường là
      • Từ khóa call: đây là log cuộc gọi điện thoại
      • <from_number> và <to_number>: là SDT gọi và nhận cuộc gọi, là kiểu xâu ký tự độ dài 10 (chỉ gồm các chữ số 0-9)
      • <date>: Là ngày thực hiện cuộc gọi theo định dạng YYYY-MM-DD (VD. 2022-10-21)
      • <from_time> và <end_time>: Là thời gian bắt đầu, kết thúc cuộc gọi trong ngày (định dạng theo hh:mm:ss, VD. 10:07:23)
Chú ý: 
      • Số lượng log cuộc gọi này có thể lớn tới 100000 dòng
      • Các tham số ngăn cách với nhau bởi 1 dấu cách trống
      Các truy vấn dữ liệu log được đưa vào với định dạng bắt đầu bằng dấu ?, trong đó
      • ?check_phone_number: in ra màn hình (dòng mới) giá trị 1 nếu các số điện thoại đều hợp lệ
      • ?number_calls_from <phone_number>: in ra màn hình (dòng mới) số cuộc gọi được xuất phát 
      từ SDT <phone_number>
      • ?number_total_calls: in ra màn hình (dòng mới) tổng số cuộc gọi có trong log
      • ?count_time_calls_from <phone_number>: in ra màn hình (dòng mới) toognr thời gian gọi (tính theo second) xuất phát từ SDT <phone_number>
Chú ý: 
      • Số lượng truy vấn cũng có thể lên tới 100000 dòng
      • Các tham số ngăn cách với nhau bởi 1 dấu cách trống

Sample Test
Input:
      call 0912345678 0132465789 2022-07-12 10:30:23 10:32:00
      call 0912345678 0945324545 2022-07-13 11:30:10 11:35:11
      call 0132465789 0945324545 2022-07-13 11:30:23 11:32:23
      call 0945324545 0912345678 2022-07-13 07:30:23 07:48:30
      #
      ?check_phone_number
      ?number_calls_from 0912345678
      ?number_total_calls
      ?count_time_calls_from 0912345678
      ?count_time_calls_from 0132465789
      #
Output:
      1
      2
      4
      398
      120
*/

#include <bits/stdc++.h>
using namespace std;

bool checkPhone(string fnum){
	if(fnum.length() != 10){
		return false;
	}
	for(int i = 0; i < fnum.length(); i++){
		if(!fnum[i] >= '0' && fnum[i] <= '9'){
			return false;
		}
	}
	return true;
}

int countTime(string ftime, string etime){
	int startTime = 3600*((ftime[0]-'0')*10 + ftime[1]-'0') + 60*((ftime[3]-'0')*10+ftime[4]-'0') + (ftime[6]-'0')*10+ftime[7]-'0';
	int endTime = 3600*((etime[0]-'0')*10 + etime[1]-'0') + 60*((etime[3]-'0')*10+etime[4]-'0') + (etime[6]-'0')*10+etime[7]-'0';
	return endTime-startTime;
}

map<string, int> numberCalls, timeCalls;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	string type;
	int totalCalls = 0;
	int incorrectPhone = 0;
	do{
		cin >> type;
		if(type == "#") continue;
		++totalCalls;
		string fnum, tnum, date, ftime, etime;
		cin >> fnum >> tnum >> date >> ftime >> etime;
		if(!checkPhone(fnum) || !checkPhone(tnum)){
			++incorrectPhone;
		}
		numberCalls[fnum]++;
		timeCalls[fnum] += countTime(ftime, etime);
	}while(type != "#");
	
	do{
		cin >> type;
		string S;
		if(type == "#") break;
		else if(type == "?check_phone_number"){
			if(incorrectPhone == 0) cout << 1 << "\n";
			else cout << "0" << "\n";
		}
		else if(type == "?number_calls_from"){
			cin >> S;
			cout << numberCalls[S] << "\n";
		}
		else if(type == "?number_total_calls"){
			cout << totalCalls << "\n";
		}
		else if(type == "?count_time_calls_from"){
			cin >> S;
			cout << timeCalls[S] << "\n";
		}
	}while(type != "#");
	return 0;
}
