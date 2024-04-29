import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class P29721 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        List<Position> piecePositions = new ArrayList<>();
        for (int i = 0; i < k; i++) {
            piecePositions.add(new Position(sc.nextInt(), sc.nextInt()));
        }
        Set<Position> results = new HashSet<>();
        for (Position piecePosition : piecePositions) {
            results.addAll(piecePosition.nexts(n));
        }
        piecePositions.forEach(results::remove);
        System.out.println(results.size());
    }
    static class Position {
        int x;
        int y;

        public Position(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public List<Position> nexts(int n) {
            List<Position> positions = new ArrayList<>();
            Position left = left();
            Position right = right();
            Position up = up();
            Position down = down();
            if (up.x >= 1 && up.x <= n && up.y >= 1 && up.y <=n) {
                positions.add(up);
            }
            if (down.x >= 1 && down.x <= n && down.y >= 1 && down.y <=n) {
                positions.add(down);
            }
            if (left.x >= 1 && left.x <= n && left.y >= 1 && left.y <=n) {
                positions.add(left);
            }
            if (right.x >= 1 && right.x <= n && right.y >= 1 && right.y <=n) {
                positions.add(right);
            }
            return positions;
        }
        public Position left() {
            return new Position(x - 2, y);
        }
        public Position right() {
            return new Position(x + 2, y);
        }
        public Position up() {
            return new Position(x, y - 2);
        }
        public Position down() {
            return new Position(x, y + 2);
        }
        @Override
        public boolean equals(Object o) {
            if (this == o) {
                return true;
            }
            if (o == null || getClass() != o.getClass()) {
                return false;
            }

            Position position = (Position) o;

            if (x != position.x) {
                return false;
            }
            return y == position.y;
        }

        @Override
        public int hashCode() {
            int result = x;
            result = 31 * result + y;
            return result;
        }
    }
}
