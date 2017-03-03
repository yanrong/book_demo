package com.yarin.android.Examples_03_01;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

/**
 * ��Examples_02_01������һ��ʹ��2����Activity,
 * ǰ������֪��ûʹ��һ��Activity�������ڡ�AndroidManifest.xml����
 * ����������
 */
public class Activity01 extends Activity
{
	public void onCreate(Bundle savedInstanceState)
	{
		super.onCreate(savedInstanceState);
		/* ������ʾmain.xml���� */
		setContentView(R.layout.main);
		/* findViewById(R.id.button1)ȡ�ò���main.xml�е�button1 */
		Button button = (Button) findViewById(R.id.button1);
		/* ����button���¼���Ϣ */
		button.setOnClickListener(new Button.OnClickListener() {
			public void onClick(View v)
			{
				/* �½�һ��Intent���� */
				Intent intent = new Intent();
				/* ָ��intentҪ�������� */
				intent.setClass(Activity01.this, Activity02.class);
				/* ����һ���µ�Activity */
				startActivity(intent);
				/* �رյ�ǰ��Activity */
				Activity01.this.finish();
			}
		});
	}
}
