---
title: Implementing post series in Hugo
date: 2020-05-30
feature_img: /uploads/hugo-series.svg 
tags:
- hugo
- tutorial
series: How to Hugo
---

Want to write a series of posts, without linking them to each other manually? dev.to has this feature. With Hugo, we can implement it with some programming. In this post I'll explain how to add series to your Hugo blog.

## Taxonomies

Hugo has this amazing feature called Taxonomies. Using simple key-value pairs in your content's frontmatter, you can define relationships between different pages. The most common taxonomy used by bloggers is tags. Here's how I define taxonomies using YAML frontmatter in Hugo:

```yaml
---
title: Implementing series of posts in Hugo
date: 2020-05-30
tags:
- hugo
- tutorial
---
```

You may have used tags taxonomy in hugo before. The key `tags` is called the taxonomy term, and the list of tags is the value. This relates our post to the two tags - `hugo` and `tutorial`.

However, what many people don't realise, is that:

1. You can define custom taxonomies in your config.
2. You can use strings instead of values in taxonomy values!

So, we are gonna define a new taxonomy so that your frontmatter is gonna look like this:

```yaml
---
title: Implementing series of posts in Hugo
date: 2020-05-30
tags:
- hugo
- tutorial
series: Hugo Tutorials
---
```

### Documentation

Before we start, if you wish to read more about Taxonomies and implement relationships yourself, [here is the link to the documentation](https://gohugo.io/content-management/taxonomies/).

## Defining custom taxonomy

First task is to define a new taxonomy term. This can be done in the `config` file. Here I use an example of `config.yaml` file. The default configuration contains:

```yaml
taxonomies:
  category: categories
  tag: tags
```

The format is `sigular word: plural word` in yaml. In template lookup, it can look for the singular word (`layouts/taxonomy/tag.html`) as well as the plural word (`layouts/tags/list.html`). This won't be a problem here because plural of series is well, series 😛

Let's add a new series taxonomy as so:

```yaml
taxonomies:
  category: categories
  tag: tags
  series: series
```

Note that if you use a `config.toml` - the default config file in most hugo websites, the syntax is:

```toml
[taxonomies]
  category = "categories"
  series = "series"
  tag = "tags"
```

Congratualtions, you defined a new relationship between your content! You can now use it your frontmatter as mentioned in the previous section.

## Themes

There are a few themes out there which may use this taxonomy, but your theme probably doesn't support it. Let's add a few code snippets to your layouts to show that your post belongs in a series.

### List page

Before we start, you can define a custom list page for your new taxonomy. The easiest way is to define a new `layouts/taxonomy/series.html` or a `layouts/series/list.html` template. Of course, [Hugo will use the default list template](https://gohugo.io/templates/lookup-order/) if none of these are defined. I do, however, suggest defining a custom list template for adding some extra jazz to your post series, so that your page doesn't look the same as a tags page. It's completely up to you. My website does define a separate series and a posts page.

### Adding series to your blog single template

If you ever want to refer to the series a post belongs to, in the `layouts/blog/single.html` or whichever template is used for your blog posts content, you can use `.Params.series` to get the name of your post series in string format. You will have to define hrefs yourself.

Here, I define which series a post was added to, and link the viewer to the list page for that series:

```go-html-template
{{ if .Params.series }}
  Published in series <a class="text-dark" href="/series/{{ .Params.series | urlize }}">{{ .Params.series }}</a>
{{ end }}
```

In the above example, I use `urlize` filter to slugify the string (that is, lowercase and replace spaces with hyphens). You can also assign it to a variable with `{{ $series = .Params.series }}`, or use a `with` block for simplicity.

How do we link the user to all other posts in the series? This one's a little tricky, since `.Params.series` only gave us a string, not a [Taxonomy struct](https://gohugo.io/variables/taxonomy/) which will have some implementation methods. We will have to extract the Taxonomy struct from the `map` in the site variable, `.Site` as follows:

```go-html-template
{{ $key := .Params.series | urlize }}
{{ $series := index .Site.Taxonomies.series $key }}
```

`index` function is used for extracting a value from a `map` or an `array`, given its key as the second argument. `.Site.Taxonomies` returns a map of taxonomies terms to taxonomy variables.

Now you can use the list of pages however you like!

```go-html-template
{{ range $series.Pages }}
  <a href="{{ .Permalink }}">
    {{ .Title }}
  </a>
{{ end }}
```

There you go! Happy posting!

If you wish to see how I've implemented series on this website, you can checkout the [repository here](https://github.com/vixrant/personal-website). Theme credits - [Hugo UILite](https://themes.gohugo.io/hugo-uilite/).
