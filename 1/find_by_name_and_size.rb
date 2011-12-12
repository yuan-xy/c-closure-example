def find(dir,find_str,min_byte)
	Dir.open(dir).each do |x|
		full_path = dir+x
		puts "#{x}, #{File.size(full_path)}" if x.start_with?(find_str) && File.size(full_path)>min_byte
	end
end

if ARGV.length==3
	find(ARGV[0],ARGV[1],ARGV[2].to_i)
else
	find("./", "a", 10)
end

