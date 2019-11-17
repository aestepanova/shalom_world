program lab5;

{$APPTYPE CONSOLE}

{$R *.res}

  type person=record
    fio: string[80];
    group: string[7];
    group_num: string[3];
  end;

  var
    f, f2: text;
    i1, i, j, k, t, id_max: integer;
    group1, tire, x, value, num:string;
    max_group:string;
    max, tmp: person;
    var student: array [1..10] of person;
                      {основная программа}
begin
    assign (f, 'E:\labs\AEStepanova_labs\5.17\список1.txt');{'E:\labs\AEStepanova_labs\5.17\список1.txt');}           {G:\labs\AEStepanova_labs\5.17}
    reset(f);
    assign (f2, 'E:\labs\AEStepanova_labs\5.17\список2.txt');          {G:\labs\AEStepanova_labs\5.17}
    rewrite(f2);

    tire:='-';
    j:=0;

    writeln('Initial list: ');
    writeln('');

    while not Eof(f) do begin
        readln(f, x);
        writeln(x);

        j:=j+1;
        i1:=pos(tire, x);
        i:=i1-3;
        group1:=copy(x,i,7)+' ';
        num:= copy(x,i1+1,3);
        delete(x,i,7);

        student[j].fio := x;
        student[j].group := group1;
        student[j].group_num:=num;
        insert(group1, x, 1);
    end;
    close(f);
    {сортировка}
    for i := 1 to j do
        begin
        for k:=i+1 to j do
            begin
                if student[k].group_num < student[i].group_num then
                    begin
                        tmp:=student[i];
                        student[i]:=student[k];
                        student[k]:= tmp;
                    end;
            end;
        end;

    for k:=1 to j do begin
      writeln(f2, student[k].group + ' ' + student[k].fio);
    end;

    close(f2);
    readln;
end.
