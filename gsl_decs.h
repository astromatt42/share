#ifndef gsl_decs_h
#define gsl_decs_h

#include <gsl_spline.h>
#include <gsl_spline2d.h>


//Constructor for 1D spline object to have it all in one place, so we don't need to pass spline and acc separately.
typedef struct gsl_spline_obj_1Ds 
{
    gsl_spline *spline;
    gsl_interp_accel *acc;
    size_t nx;
    double x_lim[2];
} gsl_spline_object_1D;

//Constructor for 2D spline object to have it all in one place, so we don't need to pass spline and acc separately.
typedef struct gsl_spline_obj_2Ds
{
    gsl_spline2d *spline;
    gsl_interp_accel *xacc, *yacc;
    size_t nx, ny;
    double x_lim[2], y_lim[2];
} gsl_spline_object_2D;

gsl_spline_object_2D gsl_so2D( size_t nx, size_t ny, double *xdata, double *ydata, double *zdata );
gsl_spline_object_1D gsl_so1D( size_t nx, double *xdata, double *ydata );

/*
 * Function to populate 1D spline object
 */
gsl_spline_object_1D gsl_so1D( size_t nx, double *xdata, double *ydata )
{
    gsl_spline_object_1D gsl_so1D;
    gsl_so1D.acc = gsl_interp_accel_alloc();
    gsl_so1D.spline = gsl_spline_alloc( gsl_interp_linear, nx);
    gsl_spline_init( gsl_so1D.spline, xdata, ydata, nx);
    gsl_so1D.nx = nx;
    gsl_so1D.x_lim[0] = xdata[0];
    gsl_so1D.x_lim[1] = xdata[nx-1];
    return gsl_so1D;
}

void gsl_so1D_free( gsl_spline_object_1D gso1D )
{
    gsl_spline_free( gso1D.spline );
    gsl_interp_accel_free( gso1D.acc );
}

/*
 * Function to populate 2D spline object
 * z[i,j] = za[j * xsize + i], where i,j is x,y
 */
gsl_spline_object_2D gsl_so2D( size_t nx, size_t ny, double *xdata, double *ydata, double *zdata )
{
    gsl_spline_object_2D gsl_so2D;
    gsl_so2D.spline = gsl_spline2d_alloc( gsl_interp2d_bilinear, nx, ny );
    gsl_so2D.xacc = gsl_interp_accel_alloc();
    gsl_so2D.yacc = gsl_interp_accel_alloc();
    gsl_spline2d_init( gsl_so2D.spline, xdata, ydata, zdata, nx, ny);
    gsl_so2D.nx = nx;
    gsl_so2D.ny = ny;
    gsl_so2D.x_lim[0] = xdata[0];
    gsl_so2D.x_lim[1] = xdata[nx-1];
    gsl_so2D.y_lim[0] = ydata[0];
    gsl_so2D.y_lim[1] = ydata[ny-1];
    return gsl_so2D;
}

void gsl_so2D_free( gsl_spline_object_2D gso2D )
{
    gsl_spline2d_free( gso2D.spline );
    gsl_interp_accel_free( gso2D.xacc );
    gsl_interp_accel_free( gso2D.yacc );
}

double gsl_so1D_eval( gsl_spline_object_1D gsl_so1D, double x )
{
    if (x >= gsl_so1D.x_lim[0] && x <= gsl_so1D.x_lim[1])
    {
        return gsl_spline_eval( gsl_so1D.spline, x, gsl_so1D.acc );
    }
    else
    {
        return 0.;
    }
}

double gsl_so2D_eval( gsl_spline_object_2D gsl_so2D, double x, double y )
{
    if ( x >= gsl_so2D.x_lim[0] && x <= gsl_so2D.x_lim[1] && y >= gsl_so2D.y_lim[0] && y <= gsl_so2D.y_lim[1] )
    {
        return gsl_spline2d_eval( gsl_so2D.spline, x, y, gsl_so2D.xacc, gsl_so2D.yacc );
    }
    else
    {
        return 0.;
    }
}



#endif
