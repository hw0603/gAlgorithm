package org.example.p30804;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] list = new int[n+1];
        String line = br.readLine();
        String[] split = line.split(" ");
        for (int i = 0; i < n; i++) {
            list[i] = Integer.parseInt(split[i]);
        }
        // 지금 조건을 만족하면, 뒤에서 하나 덜 빼보기, 조건을 만족하지 않으면 앞에서 빼기
        // 조건을 만족하는 경우 중 최대 길이가 답
        int left = 0;
        int right = 1; // 포함 안함
        int max = 0;
        int[] count = new int[10];
        count[list[left]]++;
        int kind = 1;
        while (right <= n) {
            if (kind > 2) {
                count[list[left]]--;
                left++;
                int c= 0;
                for (int i = 1; i < 10; i++) {
                    if(count[i]!=0){
                        c++;
                    }
                }
                kind = c;
            }else { // 조건 만족
                max = Math.max(max, right - left); // 만족하니까 최대값 갱신
                count[list[right]]++;// 지금 오른쪽을 포함
                right++; // 끝 값 증가
                int c= 0;
                for (int i = 1; i < 10; i++) {
                    if(count[i]!=0){
                        c++;
                    }
                }
                kind = c;
            }
        }
        System.out.println(max);
    }
}

