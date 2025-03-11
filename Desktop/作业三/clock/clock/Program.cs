using System;
using System.Threading;

// 闹钟类
public class AlarmClock
{
    public event EventHandler Tick;
    public event EventHandler Alarm;

    private int interval;
    private int alarmTime;

    public AlarmClock(int interval, int alarmTime)
    {
        this.interval = interval;
        this.alarmTime = alarmTime;
    }

    // 启动
    public void Start()
    {
        int elapsedTime = 0;

        while (elapsedTime < alarmTime)
        {
            // 触发嘀嗒
            OnTick();
            Thread.Sleep(interval * 1000); // 等待指定的时间间隔
            elapsedTime += interval;
        }

        // 触发响铃
        OnAlarm();
    }

    public virtual void OnTick()
    {
        Tick?.Invoke(this, EventArgs.Empty);
    }

    public virtual void OnAlarm()
    {
        Alarm?.Invoke(this, EventArgs.Empty);
    }
}

// 主程序
class Program
{
    public static void Main(string[] args)
    {
        // 嘀嗒间隔为1秒，响铃时间为10秒
        AlarmClock alarmClock = new AlarmClock(1, 10);

        alarmClock.Tick += (sender, e) =>
        {
            Console.WriteLine("嘀嗒...");
        };

        alarmClock.Alarm += (sender, e) =>
        {
            Console.WriteLine("响铃，时间到了！");
        };

        // 启动闹钟
        alarmClock.Start();
    }
}