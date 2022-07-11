private:
System::Void 模拟_Click(System::Object ^ sender, System::EventArgs ^ e)
{
    int x = Convert::ToInt32(textBox1->Text);
    int y = Convert::ToInt32(textBox2->Text);
    int dx[5] = {0, -1, 0, 1, 0};
    int dy[5] = {0, 0, 1, 0, -1};
    int manX = 0;
    int manY = 0;
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            if (mapArray[i, j]->Equals(4))
            {
                manX = i;
                manY = j;
            }
        }
    }
    for (int i = 0; i < (int)AnsArray->Count; i++)
    {
        Console::WriteLine("{0}", i);
        for (int j = 0; j < x; j++)
        {
            for (int k = 0; k < y; k++)
            {
                Console::Write("{0} ", mapArray[j, k]);
            }
            Console::WriteLine();
        }
        int tmpOldMan = (int)mapArray[manX, manY];
        int tmpNewMan = (int)mapArray[manX + dx[(int)AnsArray[i]], manY + dy[(int)AnsArray[i]]];
        int tmpNewBox = (int)mapArray[manX + 2 * dx[(int)AnsArray[i]], manY + 2 * dy[(int)AnsArray[i]]];
        // 1
        if (mapArray[manX, manY]->Equals(4))
        {
            // 1.1
            if (mapArray[manX + dx[(int)AnsArray[i]], manY + dy[(int)AnsArray[i]]]->Equals(2))
            {
                mapArray[manX, manY] = 5;
                mapArray[manX + dx[(int)AnsArray[i]], manY + dy[(int)AnsArray[i]]] = 4;
                if (mapArray[manX + 2 * dx[(int)AnsArray[i]], manY + 2 * dy[(int)AnsArray[i]]]->Equals(5)) //新位置变箱子
                {
                    mapArray[manX + 2 * dx[(int)AnsArray[i]], manY + 2 * dy[(int)AnsArray[i]]] = 2;
                }
                else
                { //变箱子+target
                    mapArray[manX + 2 * dx[(int)AnsArray[i]], manY + 2 * dy[(int)AnsArray[i]]] = 3;
                }
                // dataGridView1
            }
            // 1.2
            if (mapArray[manX + dx[(int)AnsArray[i]], manY + dy[(int)AnsArray[i]]]->Equals(3))
            {
                mapArray[manX, manY] = 5;
                mapArray[manX + dx[(int)AnsArray[i]], manY + dy[(int)AnsArray[i]]] = 7;
                if (mapArray[manX + 2 * dx[(int)AnsArray[i]], manY + 2 * dy[(int)AnsArray[i]]]->Equals(5)) //新位置变箱子
                {
                    mapArray[manX + 2 * dx[(int)AnsArray[i]], manY + 2 * dy[(int)AnsArray[i]]] = 2;
                }
                else
                { //变箱子+target
                    mapArray[manX + 2 * dx[(int)AnsArray[i]], manY + 2 * dy[(int)AnsArray[i]]] = 3;
                }
            }
            // 1.3
            if (mapArray[manX + dx[(int)AnsArray[i]], manY + dy[(int)AnsArray[i]]]->Equals(5))
            {
                mapArray[manX, manY] = 5;
                mapArray[manX + dx[(int)AnsArray[i]], manY + dy[(int)AnsArray[i]]] = 4;
            }
            // 1.4
            if (mapArray[manX + dx[(int)AnsArray[i]], manY + dy[(int)AnsArray[i]]]->Equals(6))
            {
                mapArray[manX, manY] = 5;
                mapArray[manX + dx[(int)AnsArray[i]], manY + dy[(int)AnsArray[i]]] = 7;
            }
        }
        // 2
        else
        {
        }
        manX = manX + dx[(int)AnsArray[i]];
        manY = manY + dy[(int)AnsArray[i]];
        // System::Threading::Thread::Sleep(500);
        // System::Threading::Tasks::Task::Delay(10000);

        DateTime curr = DateTime::Now;
        while (curr.AddMilliseconds(1000) > DateTime::Now)
        {
            Application::DoEvents();
        }
        // await Task.Delay(1000);
        // MessageBox::Show("下一步");
        for (int j = 0; j < x; j++)
        {
            for (int k = 0; k < y; k++)
            {
                if (mapArray[j, k]->Equals(1))
                {
                    dataGridView1[k, j]->Value = img_brick;
                }
                else if (mapArray[j, k]->Equals(2))
                {
                    dataGridView1[k, j]->Value = img_box;
                }
                else if (mapArray[j, k]->Equals(3))
                {
                    dataGridView1[k, j]->Value = img_box_target;
                }
                else if (mapArray[j, k]->Equals(4))
                {
                    dataGridView1[k, j]->Value = img_man;
                }
                else if (mapArray[j, k]->Equals(5))
                {
                    dataGridView1[k, j]->Value = img_ground;
                }
                else if (mapArray[j, k]->Equals(6))
                {
                    dataGridView1[k, j]->Value = img_target;
                }
                dataGridView1->Update();
            }
        }

        // MessageBox::Show("这里会马上显示");
    }
}
