package com.mousebirdconsulting.maply;

public class MaplyRenderer 
{
	MaplyRenderer()
	{
		initialise();		
	}

	public void finalize()
	{
		dispose();
	}

	public boolean setup()
	{
//		return resize();
		return true;
	}
	
	public boolean surfaceChanged(int width,int height)
	{
		return resize(width,height);
	}
	
	public void doRender()
	{
		render();
	}

	public native void setScene(MapScene scene);
	public native void setView(MapView view);
	protected native boolean teardown();
	protected native boolean resize(int width,int height);
	protected native void render();
	
	protected native void initialise();
	public native void dispose();
	private long nativeHandle;
	
	static
	{
		System.loadLibrary("Maply");
	}
}