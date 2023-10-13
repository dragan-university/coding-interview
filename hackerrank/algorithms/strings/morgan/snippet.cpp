
/* Ruby solution
gets.to_i.times do
  a, b, c = gets.strip << '|', gets.strip << '|', ''
  i, j = 0, 0
  until i == a.length - 1 || j == b.length - 1
    if a[i..-1] < b[j..-1]
      c << a[i]
      i += 1
    else
      c << b[j]
      j += 1
    end
  end
  puts c << a[i..-2] << b[j..-2]
end
*/
