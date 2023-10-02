bool isPaintPossible(vector<int> boards, int k, int mid) {
    int paintercount = 1;
    int timecount = 0;

    for (int i=0; i<boards.size(); i++) {
		if (timecount + boards[i] <= mid) {
			timecount += boards[i]; 
		}
		else {
			paintercount++;
			if (paintercount>k || boards[i]>mid) {
				return false;
			}
			timecount = boards[i];
		}
	}
	return true;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    //    Write your code here.
    int s = 0;
    int sum = 0;

    for (int i=0; i<boards.size(); i++) {
        sum += boards[i];
    }

    int e = sum;
    int ans = -1;
    int mid = s + (e-s)/2;

    while (s<=e) {
        if (isPaintPossible(boards, k, mid)) {
            ans = mid;
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }

        mid = s + (e-s)/2;
    }
    return ans;
}