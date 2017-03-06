program testsum
  implicit none

  integer, parameter :: n=200
  integer :: data(n), asum, i

  interface
	      subroutine sum_abs_( arre, num , res) bind ( c )
	        use iso_c_binding
	        integer ( c_int) :: arre(*)
	        integer ( c_int ) :: num
	        integer ( c_int ) :: res
	      end subroutine sum_abs_
  end interface

  do i=1,200
    data(i) = i-100
  end do

  call sum_abs(data,n,asum)
  print*, 'sum=',asum
end program testsum 


