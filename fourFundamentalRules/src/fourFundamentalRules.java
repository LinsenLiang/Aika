import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
import java.util.Random;

public class fourFundamentalRules extends JFrame implements ActionListener {
    JLabel L_number, L_test, L_answer, L_info, L_info_pr, L_test_pr;
    JTextField T_inputText, T_answerText;
    JButton Btn_change, Btn_next, Btn_submit, Btn_Factorial;
    int backColor = 0;
    int number;
    int answer;
    int result;
    int num1, num2, num3;
    int op1, op2;
    int right = 0;
    int wrong = 0;
    int n;
    int j = 2;

    public fourFundamentalRules() {
        super("四则运算");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(800, 250);
        this.setLocationRelativeTo(null);
        L_number = new JLabel("输入出题数(1~5):");
        L_test = new JLabel("题目:");
        L_answer = new JLabel("输入答案:");
        L_info = new JLabel("反馈信息:");
        L_info_pr = new JLabel(" ");
        Btn_change = new JButton("换肤");
        Btn_next = new JButton("下一题");
        Btn_submit = new JButton("提交答案");
        Btn_Factorial = new JButton("阶乘运算");
        L_test_pr = new JLabel(" ");
        T_inputText = new JTextField();
        T_answerText = new JTextField();
        T_inputText.addActionListener(this);
        T_answerText.addActionListener(this);
        Btn_change.addActionListener(this);
        Btn_next.addActionListener(this);
        Btn_submit.addActionListener(this);
        Btn_Factorial.addActionListener(this);
        GridLayout layout = new GridLayout(6, 2, 5, 5);
        getContentPane().setLayout(layout);
        getContentPane().setBackground(Color.white);
        L_number.setHorizontalAlignment(L_number.CENTER);
        L_test.setHorizontalAlignment(L_test.CENTER);
        L_answer.setHorizontalAlignment(L_answer.CENTER);
        L_info.setHorizontalAlignment(L_info.CENTER);
        L_info_pr.setHorizontalAlignment(L_info_pr.CENTER);
        L_test_pr.setHorizontalAlignment(L_info_pr.CENTER);
        T_inputText.setHorizontalAlignment(T_inputText.CENTER);
        T_answerText.setHorizontalAlignment(T_inputText.CENTER);
        add(L_number);
        add(T_inputText);
        add(L_test);
        add(L_test_pr);
        add(L_answer);
        add(T_answerText);
        add(L_info);
        add(L_info_pr);
        add(Btn_submit);
        add(Btn_next);
        add(Btn_change);
        add(Btn_Factorial);
        setVisible(true);
        setResizable(false);
    }

    public static void main(String[] args) {
        setUIFont();
        fourFundamentalRules frame = new fourFundamentalRules();
    }


    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == T_inputText) {
            right = 0;
            wrong = 0;
            L_info_pr.setText("");
            T_answerText.setText("");
            String str_num = T_inputText.getText();
            boolean isNumeric = isNumeric(str_num);
            if (isNumeric) {
                number = Integer.parseInt(str_num);
                n = number;
                if (number > 0 && number <= 5) {
                    L_test.setText("题目1:");
                    test();

                } else {
                    L_info_pr.setText("请输入1~5的值！");
                }
            } else {
                L_info_pr.setText("输入含有非法字符，请重新输入！");
            }


        }


        /**
         * 提交答案
         */
        else if (e.getSource() == Btn_submit) {
            String str_answer = T_answerText.getText();
            answer = Integer.parseInt(str_answer);
            if (answer == result) {
                L_info_pr.setText("回答正确！");
                right++;
            } else {
                L_info_pr.setText("回答错误！正确答案为：" + result);
                wrong++;
            }
        }


        /**
         * 下一题
         */

        else if (e.getSource() == Btn_next) {
            if (n > 1) {
                n--;
                L_info_pr.setText("");
                T_answerText.setText("");
                test();
                L_test.setText("题目" + j + ":");
                j++;
            } else {
                L_info_pr.setText("题目已做完！正确题数：" + right + ";错误题数：" + wrong);
            }
        }


        /**
         * 换肤
         */
        else if (e.getSource() == Btn_change) {
            switch (backColor) {
                case 0:
                    this.getContentPane().setBackground(Color.red);
                    break;
                case 1:
                    this.getContentPane().setBackground(Color.lightGray);
                    break;
                case 2:
                    this.getContentPane().setBackground(Color.GREEN);
                    break;
                case 3:
                    this.getContentPane().setBackground(Color.yellow);
                    break;
                case 4:
                    this.getContentPane().setBackground(Color.blue);
                    break;
                case 5:
                    this.getContentPane().setBackground(Color.magenta);
                    break;
                case 7:
                    this.getContentPane().setBackground(Color.white);
                    break;
            }
            backColor++;
            backColor = backColor % 7;
        }

        /**
         * 阶乘运算
         */
        else if (e.getSource() == Btn_Factorial) {
            L_test.setText("题目:");
            T_inputText.setText("");
            L_info_pr.setText("");
            T_answerText.setText("");
            number = (int) (Math.random() * 10);
            L_test_pr.setText(number + "!");
            if (number == 0) {
                result = 1;
            } else {
                for (int i = 1; i <= number; i++) {
                    result = result * i;

                }

            }
        }
    }

    public static void setUIFont() {
        Font f = new Font("宋体", Font.PLAIN, 20);
        String names[] = {"Label", "Button", "TextField",};
        for (String item : names) {
            UIManager.put(item + ".font", f);
        }
    }

    public void test() {
        Random rand = new Random();
        num1 = rand.nextInt() % 99 + 1;
        num2 = rand.nextInt() % 99 + 1;
        num3 = rand.nextInt() % 99 + 1;
        op1 = (int) (Math.random() * 4 + 1);
        op2 = (int) (Math.random() * 4 + 1);
        String str_num1 = String.valueOf(num1);
        String str_num2 = String.valueOf(num2);
        String str_num3 = String.valueOf(num3);
        if (num1 < 0) {
            str_num1 = String.valueOf("(" + num1 + ")");
        }
        if (num2 < 0) {
            str_num2 = String.valueOf("(" + num2 + ")");
        }
        if (num3 < 0) {
            str_num3 = String.valueOf("(" + num3 + ")");
        }
        switch (op1) {
            case 1:
                switch (op2) {
                    case 1:
                        L_test_pr.setText(str_num1 + "+" + str_num2 + "+" + str_num3 + "=");
                        result = num1 + num2 + num3;
                        break;
                    case 2:
                        L_test_pr.setText(str_num1 + "+" + str_num2 + "-" + str_num3 + "=");
                        result = num1 + num2 - num3;
                        break;
                    case 3:
                        L_test_pr.setText(str_num1 + "+" + str_num2 + "*" + str_num3 + "=");
                        result = num1 + num2 * num3;
                        break;
                    case 4:
                        L_test_pr.setText(str_num1 + "+" + str_num2 + "÷" + str_num3 + "=");
                        result = num1 + num2 / num3;
                        break;
                }
                break;

            case 2:
                switch (op2) {
                    case 1:
                        L_test_pr.setText(str_num1 + "-" + str_num2 + "+" + str_num3 + "=");
                        result = num1 - num2 + num3;
                        break;
                    case 2:
                        L_test_pr.setText(str_num1 + "-" + str_num2 + "-" + str_num3 + "=");
                        result = num1 - num2 - num3;
                        break;
                    case 3:
                        L_test_pr.setText(str_num1 + "-" + str_num2 + "*" + str_num3 + "=");
                        result = num1 - num2 * num3;
                        break;
                    case 4:
                        L_test_pr.setText(str_num1 + "-" + str_num2 + "÷" + str_num3 + "=");
                        result = num1 - num2 / num3;
                        break;
                }
                break;


            case 3:
                switch (op2) {
                    case 1:
                        L_test_pr.setText(str_num1 + "*" + str_num2 + "+" + str_num3 + "=");
                        result = num1 * num2 + num3;
                        break;
                    case 2:
                        L_test_pr.setText(str_num1 + "*" + str_num2 + "-" + str_num3 + "=");
                        result = num1 * num2 - num3;
                        break;
                    case 3:
                        L_test_pr.setText(str_num1 + "*" + str_num2 + "*" + str_num3 + "=");
                        result = num1 * num2 * num3;
                        break;
                    case 4:
                        L_test_pr.setText(str_num1 + "*" + str_num2 + "÷" + str_num3 + "=");
                        result = num1 * num2 / num3;
                        break;
                }
                break;


            case 4:
                switch (op2) {
                    case 1:
                        L_test_pr.setText(str_num1 + "÷" + str_num2 + "+" + str_num3 + "=");
                        result = num1 / num2 + num3;
                        break;
                    case 2:
                        L_test_pr.setText(str_num1 + "÷" + str_num2 + "-" + str_num3 + "=");
                        result = num1 / num2 - num3;
                        break;
                    case 3:
                        L_test_pr.setText(str_num1 + "÷" + str_num2 + "*" + str_num3 + "=");
                        result = num1 / num2 * num3;
                        break;
                    case 4:
                        L_test_pr.setText(str_num1 + "÷" + str_num2 + "÷" + str_num3 + "=");
                        result = num1 / num2 / num3;
                        break;
                }
                break;
        }
    }

    public static boolean isNumeric(String str) {
        for (int i = str.length(); --i >= 0; ) {
            if (!Character.isDigit(str.charAt(i))) {
                return false;
            }
        }
        return true;
    }
}