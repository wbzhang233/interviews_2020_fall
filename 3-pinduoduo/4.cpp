//
// Created by wbzhang on 2020/8/2.
//

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/*
用例1
##****
##****
******
******
******
******
* 630    1000000009
*
*
*
 */
/*
用例2
#*****
******
******
******
******
*****#
* 36

 */

/**
 * @Description:
 * @Create 2020-08-02 20:16
 * @Email:
 */
public class Main {

public static void main(String[] args) throws IOException {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            String s = null;
            char[][] matrix = new char[6][6];
            while ((s = br.readLine()) != null) {
                matrix[0] = s.toCharArray();
                for (int i = 0; i < 5; i++) {
                    matrix[i + 1] = br.readLine().toCharArray();
                }
                int res = function(matrix);
                System.out.println(res);
            }
            br.close();
    }

    static int[][] dd = new int[36][6];
    static int res = 0;
    static int Num = 0;

private static int function(char[][] matrix) {
        res = 0;
        int num = 0;
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {
                if (matrix[i][j] == '#') {
                    num++;
                }
            }
        }
        Num = num;
        backTrack(matrix, 0, 0, 0);
        return res;
    }

private static void backTrack(char[][] matrix, int count, int row, int col) {
        if (count == Num) {
            res++;
            res %= 1000000009;
            return;
        }
        int before = row*6 + col;
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {
                if (i * 6 + j < before) { // 保证往后遍历 避免重复
                    continue;
                }
                if (matrix[i][j] == '#') {
                    int index = i * 6 + j;
                    for (int t = 0; t < 6; t++) {
                        if (check(i, j, t)) {// 如果能放
                            matrix[i][j] = '*'; // 打个标记
                            dd[index][t] = 1;  // 记录这个位置中的植物
                            backTrack(matrix, count + 1, i, j);
                            dd[index][t] = 0;  // 撤销
                            matrix[i][j] = '#'; // 撤销
                        }
                    }
                }
            }
        }
        return;
    }

    // 周围四个方向
    static int[][] dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

private static boolean check(int row, int col, int kind) {
        for (int[] arr : dir) {
            int x = row + arr[0];
            int y = col + arr[1];
            if (x >= 0 && x < 6 && y >= 0 && y < 6) {
                int index = x * 6 + y;
                if (dd[index][kind] == 1) return false;
            }
        }
        return true;
    }
}