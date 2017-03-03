package com.yarin.android.Examples_04_03;

import android.app.Activity;
import android.graphics.Color;
import android.os.Bundle;
import android.widget.TextView;

public class Activity01 extends Activity
{
	/* ����TextView���� */
	private TextView textview;
	
	/** Called when the activity is first created. */
	@Override
	public void onCreate(Bundle savedInstanceState)
	{
		super.onCreate(savedInstanceState);
		setContentView(R.layout.main);
		/* ���TextView���� */
		textview = (TextView)this.findViewById(R.id.textview);
		
		String string = "TextViewʾ������ӭʹ�ã�";
		
		/* �����ı�����ɫ */
		textview.setTextColor(Color.RED);
		/* ���������С */
		textview.setTextSize(20);
		/* �������ֱ��� */
		textview.setBackgroundColor(Color.BLUE);
		/* ����TextView��ʾ������ */
		textview.setText(string);
	}
}
