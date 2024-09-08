package week17.B_31997.jminkkk;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class BOJ31997 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] str = br.readLine().split(" ");
        int n = Integer.parseInt(str[0]);
        int m = Integer.parseInt(str[1]);
        int t = Integer.parseInt(str[2]);

        List<Meeting> persons = new ArrayList<>();
        for (int  i = 0; i < n; i++) {
            str = br.readLine().split(" ");
            persons.add(new Meeting(i, Integer.parseInt(str[0]), Integer.parseInt(str[1])));
        }

        int[] closes = new int[t];
        for (int i = 0; i < m; i++) {
            str = br.readLine().split(" ");
            int person1 = Integer.parseInt(str[0]);
            int person2 = Integer.parseInt(str[1]);

            persons.get(person1 - 1).checkCommon(persons.get(person2 - 1), closes);
        }

        for (int i = 0; i < t; i++) {
            System.out.println(closes[i]);
        }
    }
}

class Meeting {
    int person;
    int start;
    int finish;

    public Meeting(int person, int start, int finish) {
        this.person = person;
        this.start = start;
        this.finish = finish;
    }

    public void checkCommon(Meeting meeting, int[] closes) {
        int startTime = Math.max(this.start, meeting.start);
        int goodByeTime = Math.min(this.finish, meeting.finish);
        for (int i = startTime; i < goodByeTime; i++) {
            closes[i]++;
        }
    }
}

