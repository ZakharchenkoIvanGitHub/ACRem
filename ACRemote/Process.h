int status_AC[5] = {0, 0, 20, 0, 15 };
char* model = NULL;

/*
0 - power
    0 - off
    1 - on
1 - mode
    0 - Auto
    1 - Fun вентилятор
    2 - Dry осушение
    3 - Cool охлаждение
    4 - Heat обогрев
2 - temp
3 - fan
    0 - Quiet тихий
    2 - Medium
    4 - Maximum
    7 - Auto
4 - swing_v
    1 - Highest
    2 - High
    3 - Middle
    4 - Low
    15 - Auto
*/

char* get_in_bracket(char* value){
  int cursor = 0;
  char* res = NULL;
  while (value[cursor]){
    if (value[cursor]=='(') 
      res = value+cursor+1;
    if (value[cursor]==')') {
      value[cursor] = '\0'; 
      return res;
      }
    cursor++;
}
return res;
}

void set_power(char* value){
    if (!strcmp(value, "On"))
      status_AC[0]=1;
    else status_AC[0]=0;
}

void set_mode(char* value){
  char* mode = get_in_bracket(value);
  if (mode){
    if (!strcmp(mode, "Auto")) {
      status_AC[1]=0;
      return;
      }
    if (!strcmp(mode, "UNKNOWN")||!strcmp(mode, "Fan")) {
      status_AC[1]=1;
      return;
      }
    if (!strcmp(mode, "Dry")) {
      status_AC[1]=2;
      return;
      }
    if (!strcmp(mode, "Cool")) {
      status_AC[1]=3;
      return;
      }
    if (!strcmp(mode, "Heat")) {
      status_AC[1]=4;
      return;
      }
  }
  else Serial.println("Ошибка определения режима работы");  
  
Serial.println("Неописаный режим работы");
    

}

void set_temp(char* value){
      value[2] = '\0'; 
      int temp = atoi(value);
      status_AC[2]=temp;
}

void set_fan(char* value){
  char* mode = get_in_bracket(value);
  if (mode){
    if (!strcmp(mode, "Auto")) {
      status_AC[3]=7;
      return;
      }
    if (!strcmp(mode, "Maximum")||!strcmp(mode, "Max")) {
      status_AC[3]=4;
      return;
      }
    if (!strcmp(mode, "Medium")||!strcmp(mode, "Med")) {
      status_AC[3]=2;
      return;
      }
    if (!strcmp(mode, "Quiet")||!strcmp(mode, "Min")) {
      status_AC[3]=0;
      return;
      }
  }
  else Serial.println("Ошибка определения скорости вентилятора");
  
Serial.println("Неописаный режим скорости вентилятора");
}

void set_swing_v(char* value){
  char* mode = get_in_bracket(value);
 // Serial.println(value);
  if (mode){
    if (!strcmp(mode, "Auto")) {
      status_AC[4]=15;
      //swing.start_swing();
      return;
      }
    if (!strcmp(mode, "Highest")) {
      status_AC[4]=1;
     // swing.stop_swing();
      return;
      }
    if (!strcmp(mode, "High")) {
      status_AC[4]=2;
     // swing.stop_swing();
      return;
      }
    if (!strcmp(mode, "Middle")) {
      status_AC[4]=3;
    //  swing.stop_swing();
      return;
      }
    if (!strcmp(mode, "Low")) {
      status_AC[4]=4;
     // swing.stop_swing();
      return;
      }
  }
  else Serial.println("Ошибка определения качания");
  
Serial.println("Неописаный режим качания");
}

void set_quiet(char* value){
      //Serial.print("Тихий режим ");
      //Serial.println(value);
}

void set_powerful(char* value){
      //Serial.print("Мощный режим ");
      //Serial.println(value);
}

void set_clock(char* value){
      //Serial.print("Часы ");
      //Serial.println(value);
}

void set_on_timer(char* value){
      //Serial.print("Таймер включения ");
      //Serial.println(value);
}

void set_off_timer(char* value){
      //Serial.print("Таймер отключения ");
      //Serial.println(value);
}

void set_values(char* key,char* value){
  
    if (!strcmp(key, "Model")){
      model = value;
    return;
  }

  if (!strcmp(key, "Power")){
    set_power(value);
    return;
  }

  if (!strcmp(key, "Mode")){
    set_mode(value);
    return;
  }

  if (!strcmp(key, "Temp")){
    set_temp(value);
    return;
  }

  if (!strcmp(key, "Fan")){
    set_fan(value);
    return;
  }

  if (!strcmp(key, "Swing(V)")){
    set_swing_v(value);
    return;
  }

  if (!strcmp(key, "Quiet")){
    set_quiet(value);
    return;
  }

  if (!strcmp(key, "Powerful")){
    set_powerful(value);
    return;
  }

  if (!strcmp(key, "Clock")){
    set_clock(value);
    return;
  }

  if (!strcmp(key, "On Timer")){
    set_on_timer(value);
    return;
  }

  if (!strcmp(key, "Off Timer")){
    set_off_timer(value);
    return;
  }




  Serial.print("dont_recognize ");
  Serial.print(key);
  Serial.print(": ");
  Serial.println(value);
  

}
