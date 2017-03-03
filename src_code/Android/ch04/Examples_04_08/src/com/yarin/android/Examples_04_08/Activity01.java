package com.yarin.android.Examples_04_08;

import android.app.Activity;
import android.os.Bundle;
import android.view.Gravity;
import android.view.View;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.CompoundButton;
import android.widget.TextView;
import android.widget.Toast;

public class Activity01 extends Activity
{
	//������ʾ��Ŀ
	TextView	m_TextView1;
	//���ύ��ť��
	Button		m_Button1;
	//4����ѡ��
	CheckBox	m_CheckBox1;
	CheckBox	m_CheckBox2;
	CheckBox	m_CheckBox3;
	CheckBox	m_CheckBox4;
	
	/** Called when the activity is first created. */
	@Override
	public void onCreate(Bundle savedInstanceState)
	{
		super.onCreate(savedInstanceState);
		setContentView(R.layout.main);

		m_TextView1 = (TextView) findViewById(R.id.TextView1);
		m_Button1 = (Button) findViewById(R.id.button1);

		/* ȡ��ÿ��CheckBox���� */
		m_CheckBox1 = (CheckBox) findViewById(R.id.CheckBox1);
		m_CheckBox2 = (CheckBox) findViewById(R.id.CheckBox2);
		m_CheckBox3 = (CheckBox) findViewById(R.id.CheckBox3);
		m_CheckBox4 = (CheckBox) findViewById(R.id.CheckBox4);

		//��ÿ��ѡ�������¼�����
		m_CheckBox1.setOnCheckedChangeListener(new CheckBox.OnCheckedChangeListener() {
			@Override
			public void onCheckedChanged(CompoundButton buttonView, boolean isChecked)
			{
				if(m_CheckBox1.isChecked())
				{
					DisplayToast("��ѡ���ˣ�"+m_CheckBox1.getText());
				}
			}
		});
		////////////////////
		m_CheckBox2.setOnCheckedChangeListener(new CheckBox.OnCheckedChangeListener() {
			@Override
			public void onCheckedChanged(CompoundButton buttonView, boolean isChecked)
			{
				if(m_CheckBox2.isChecked())
				{
					DisplayToast("��ѡ���ˣ�"+m_CheckBox2.getText());
				}
			}
		});
		/////////////////
		m_CheckBox3.setOnCheckedChangeListener(new CheckBox.OnCheckedChangeListener() {
			@Override
			public void onCheckedChanged(CompoundButton buttonView, boolean isChecked)
			{
				if(m_CheckBox3.isChecked())
				{
					DisplayToast("��ѡ���ˣ�"+m_CheckBox3.getText());
				}
			}
		});
		////////////////
		m_CheckBox4.setOnCheckedChangeListener(new CheckBox.OnCheckedChangeListener() {
			@Override
			public void onCheckedChanged(CompoundButton buttonView, boolean isChecked)
			{
				if(m_CheckBox4.isChecked())
				{
					DisplayToast("��ѡ���ˣ�"+m_CheckBox4.getText());
				}
			}
		});
		//�԰�ť�����¼�����
		m_Button1.setOnClickListener(new Button.OnClickListener() {
			public void onClick(View v)
			{
				int num = 0;
				if(m_CheckBox1.isChecked())
				{
					num++;
				}
				if(m_CheckBox2.isChecked())
				{
					num++;
				}
				if(m_CheckBox3.isChecked())
				{
					num++;
				}
				if(m_CheckBox4.isChecked())
				{
					num++;
				}
				DisplayToast("лл���룡��һ��ѡ����"+num+"�");
			}
		});
	}
	
	/* ��ʾToast  */
	public void DisplayToast(String str)
	{
		Toast toast = Toast.makeText(this, str, Toast.LENGTH_SHORT);
		//����toast��ʾ��λ��
		toast.setGravity(Gravity.TOP, 0, 220);
		//��ʾ��Toast
		toast.show();
	}
}
