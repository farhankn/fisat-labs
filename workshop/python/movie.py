import fresh_tomatoes
class Movie:
	def __init__(self, title, poster, trailer):
		self.title=title
		self.poster_image_url=poster
		self.trailer_youtube_url=trailer

movie1=Movie("Njan Steve Lopez","http://cnt.in.bookmyshow.com/events/large/ET00023241.jpg?423","https://www.youtube.com/watch?v=X2OyKsF6Tq4")
movie2=Movie("Singham Returns", "http://cnt.in.bookmyshow.com/events/large/ET00020347.jpg?423","https://www.youtube.com/watch?v=3CwQjsdE-1Q")
movie3=Movie("Anjaan","http://cnt.in.bookmyshow.com/events/large/ET00022730.jpg?423","https://www.youtube.com/watch?v=MJxEQPMh_io")

movies=[movie1,movie2,movie3]

fresh_tomatoes.open_movies_page(movies)
