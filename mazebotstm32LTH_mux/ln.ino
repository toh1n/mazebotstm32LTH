// void l_follow() {
//   while (1) { //infinite loop
// a:    reading();
//     if (sum == 0) {
//       if (flag != 's') {
//         (flag == 'l') ? motor(-6 * spl, 6 * spr) : motor(6 * spl, -6 * spr);
//         while (s[2] == 0 && s[3] == 0) reading();
//         flag = 's'; cross = 's'; pos = 0; //when you are done turning robot, make the flag to its normal state so that robot wont turn on its own when it finds no line without detecting 90degree logic
//       }
//       else if (pos > -3 && pos < 3) {
//         m2 = millis();
//         while (sum == 0) {
//           reading();
//           if (millis() - m2 > u_turn_delay) {
//             motor(0, 0); delay(100);
//             (side == 'l') ? motor(-6 * spl, 6 * spr) : motor(6 * spl, -6 * spr);
//             while (s[2] == 0 && s[3] == 0) reading();
//             pos = 0; break;
//           }
//         }
//       }
//     }
//     else if (sum == 1 || sum == 2) {  //only for straight line
//       if (cross != 's') {
//         (cross == 'l') ? motor(-6 * spl, 6 * spr) : motor(6 * spl, -6 * spr);
//         while (s[4] + s[3] + s[2] + s[1] > 0) reading();
//         while (s[2] == 0 && s[3] == 0) reading();
//         cross = 's'; flag = 's'; pos = 0;
//       }

//       pid(100, 10, 100)
//     }

//     else if (sum == 3 || sum == 4 || sum == 5) {
//       if (s[5] == 1 && s[0] == 0 && s[2] + s[3] > 0) {
//         flag = 'l';
//         while (s[5] == 1 && s[0] == 0) reading();
//         if (s[0] == 0) {
//           delay(node_delay);
//           reading();
//           if (sum != 0) if (side == 'l') cross = 'l';
//         }
//       }

//       else if (s[0] == 1 && s[5] == 0 && s[2] + s[3] > 0) {
//         flag = 'r';
//         while (s[5] == 0 && s[0] == 1) reading();
//         if (s[5] == 0) {
//           delay(node_delay);
//           reading();
//           if (sum != 0) if (side == 'r') cross = 'r';
//         }
//       }
//       m1 = millis();
//     }

//     else if (sum == 6) {
//       flag = side;
//       m2 = millis();
//       while (s[5] == 1 || s[0] == 1) {
//         reading();
//         if (millis() - m2 > stop_timer) {
//           motor(0, 0);
//           while (sum == 6) reading();
//           goto a;
//         }
//       }
//       delay(node_delay);
//       reading();
//       if (sum != 0) cross = side;
//       m1 = millis();
//     }
//     if (millis() - m1 > 500) flag = 's';
//   }
// }
